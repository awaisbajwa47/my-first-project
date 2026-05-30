#include<iostream>      // For input/output
#include <cstdlib>      // For system() function
#include <string>       // For string data type
#include <iomanip>      // For setw(), setfill()
#include <algorithm>    // For remove()
#include <fstream>      // For file handling

using namespace std;

/*
----------------------------------------------------------
Function: runCurlWithTimeout
Purpose : Runs a curl command using system()
          Returns true if command runs successfully
----------------------------------------------------------
*/
bool runCurlWithTimeout(const string& command)
{
    return system(command.c_str()) == 0;
}

/*
----------------------------------------------------------
Function: fetchWeather
Purpose : Executes curl command and stores output in file
          Reads first line from file and returns it
----------------------------------------------------------
*/
bool fetchWeather(const string& command, string& result)
{
    system((command + " > temp.txt").c_str());  // Run curl and save output

    ifstream file("temp.txt");
    if (!file) return false;

    getline(file, result);   // Read weather result
    file.close();
    remove("temp.txt");      // Delete temp file

    // Remove unwanted carriage return characters
    result.erase(remove(result.begin(), result.end(), '\r'), result.end());

    return !result.empty();
}

/*
----------------------------------------------------------
Function: showCapitalsWeather
Purpose : Displays weather of 6 capital cities
          Uses setw() for proper alignment
----------------------------------------------------------
*/
void showCapitalsWeather()
{
    string capitals[] = {
        "Islamabad", "Tokyo",
        "London", "Paris",
        "Washington", "Canberra"
    };

    cout << left;  // Left alignment

    // Display two cities per line
    for (int i = 0; i < 6; i += 2)
    {
        string out1, out2;

        string cmd1 = "curl --max-time 7 -s http://wttr.in/" + capitals[i] +
            "?format=%t+%C";
        string cmd2 = "curl --max-time 7 -s http://wttr.in/" + capitals[i+1] +
            "?format=%t+%C";

        if (!fetchWeather(cmd1, out1)) out1 = "Network issue";
        if (!fetchWeather(cmd2, out2)) out2 = "Network issue";

        cout << setw(14) << capitals[i]   << ": "
             << setw(30) << out1
             << setw(14) << capitals[i+1] << ": "
             << setw(30) << out2 << "\n";
    }

    cout << "\n";
}

/*
----------------------------------------------------------
Function: currentWeather
Purpose : Shows detailed current weather of a city
----------------------------------------------------------
*/
void currentWeather()
{
    string city;
    cout << "\nEnter city name: ";
    cin >> city;

    string command =
        "curl --max-time 7 -s http://wttr.in/" + city +
        "?format=Location:+%l\\nTemperature:+%t\\nCondition:+%C\\nHumidity:+%h\\nWind:+%w";

    cout << "\n------------------------------\n";

    if (!runCurlWithTimeout(command))
        cout << "Unable to fetch weather. Check internet.\n";
}

/*
----------------------------------------------------------
Function: todaySummary
Purpose : Displays today's weather summary
          (Morning, Afternoon, Evening, Night)
----------------------------------------------------------
*/
void todaySummary()
{
    string city;
    cout << "\nEnter city name: ";
    cin >> city;

    string command =
        "curl --max-time 7 -s http://wttr.in/" + city +
        "?format=Morning+(9AM):+%t\\n"
        "Afternoon+(3PM):+%t\\n"
        "Evening+(6PM):+%t\\n"
        "Night+(12AM):+%t\\n"
        "Condition:+%C";

    cout << "\n------------------------------\n";

    if (!runCurlWithTimeout(command))
        cout << "Network issue. Try again.\n";

    cout << "------------------------------\n";
}

/*
----------------------------------------------------------
Function: threeDayForecast
Purpose : Shows weather forecast for next 3 days
----------------------------------------------------------
*/
void threeDayForecast()
{
    string city;
    cout << "\nEnter city name: ";
    cin >> city;

    string command =
        "curl --max-time 7 -s http://wttr.in/" + city +
        "?format=Day+1:+%d:+%t\\nDay+2:+%d:+%t\\nDay+3:+%d:+%t";

    cout << "\n------------------------------\n";

    if (!runCurlWithTimeout(command))
        cout << "Unable to fetch forecast. Check internet.\n";

    cout << "------------------------------\n";
}

/*
----------------------------------------------------------
Function: main
Purpose : Program entry point
          Displays menu and calls required functions
----------------------------------------------------------
*/

int main()
{
    system("chcp 65001 > nul");   // ← ADD THIS LINE
    
    const int WIDTH = 60;

    // App header using setw and setfill
    cout << setw(WIDTH) << setfill('=') << "" << setfill(' ') << "\n";
    cout << setw((WIDTH + 11) / 2) << "WEATHER APP" << "\n";
    cout << setw(WIDTH) << setfill('=') << "" << setfill(' ') << "\n\n";

    // Show capitals weather
    showCapitalsWeather();

    // Menu options
    cout << "1. Current Weather\n";
    cout << "2. Today Summary\n";
    cout << "3. 3-Day Forecast\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1: currentWeather();    break;
        case 2: todaySummary();      break;
        case 3: threeDayForecast();  break;
        default: cout << "\nInvalid choice.\n";
    }

    return 0;
}