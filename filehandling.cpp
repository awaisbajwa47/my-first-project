#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream myFile("FILE1.txt");
    if(myFile.is_open())
    {
        string str;
        myFile>>str;
        cout<<str;
    }
    myFile.close();
    

}