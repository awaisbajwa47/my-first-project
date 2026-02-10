#include <iostream>
using namespace std;

int main() {
    int interestChoice, difficultyChoice;

    cout << "------ AI Recommendation Assistant ------" << endl;
    cout<<"Welcome! lets find the best recommendations for you"<<endl;
    cout << "Please select your interest:" << endl;
    cout << "1. Gaming" << endl;
    cout << "2. Learning" << endl;
    cout << "3. Entertainment" << endl;
    cout << "Which choice (1-3) will you make today? ";
    cin >> interestChoice;

    // Validate interest input
    if (interestChoice < 1 || interestChoice > 3) {
        cout << "Oops! Invalid choice. Please restart the program and enter your choice again." << endl;
        return 0;
    }

    cout << "Select difficulty level:" << endl;
    cout << "1. Beginner" << endl;
    cout << "2. Intermediate" << endl;
    cout << "3. Advanced" << endl;
    cout << "Select the difficulty level (1-3): ";
    cin >> difficultyChoice;

    // Validate difficulty input
    if (difficultyChoice < 1 || difficultyChoice > 3) {
        cout << "Oops! Invalid choice. Please restart the program and enter your choice again." << endl;
        return 0;
    }

    cout << "---------------------------------" << endl;
    cout << "AI Recommendation:" << endl;

    // AI decision making using switch and if-else
    if (interestChoice == 1) { // Gaming
        switch (difficultyChoice) {
            case 1:
                cout << "Try SUBWAY SURFERS or BUBBLE SHOOTER if you want to play at Beginner level." << endl;
                break;
            case 2:
                cout << "Try ASPHALT or FREE FIRE if you want to play at Intermediate level." << endl;
                break;
            case 3:
                cout << "Try FORTNITE or RDR if you want to play at Advanced level." << endl;
                break;
        }
    }
    else if (interestChoice == 2) { // Learning
        switch (difficultyChoice) {
            case 1:
                cout << "Try MATHS or COMPUTER if you want to learn at Beginner level." << endl;
                break;
            case 2:
                cout << "Try CHEMISTRY or STATISTICS if you want to learn at Intermediate level." << endl;
                break;
            case 3:
                cout << "Try AI or DATA SCIENCE if you want to learn at Advanced level." << endl;
                break;
        }
    }
    else if (interestChoice == 3) { // Entertainment
        switch (difficultyChoice) {
            case 1:
                cout << "Try COCOMELON or BULBULAY if you want Entertainment at Beginner level. " << endl;
                break;
            case 2:
                cout << "Try MR BEAST or MONEY HEIST if you want Entertainment at Intermediate level." << endl;
                break;
            case 3:
                cout << "Try GAME OF THRONES or BREAKING BAD if you want entertainment at Advanced level." << endl;
                break;
        }
    }

    return 0;
}
