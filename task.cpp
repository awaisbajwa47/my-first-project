#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream out;
    ifstream in;
    string text;
    out.open("afile.dat",ios::app);
    cout<<"Enter text (type END to stop):"<<endl;
    while(true){
        getline(cin,text);
        if(text == "END")
        break;
        out<<text<<endl;

    }
    out.close();
    in.open("afile.dat");
    cout<<"\n -- File Contents --"<<endl;
    while(getline(in,text))
    {
        cout<<text<<endl;
    }
    in.close();
    return 0;


} 