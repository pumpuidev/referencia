#include <iostream>

using namespace std;

int main()
{
    int ar,szazalek;
    string szov;
    float akc;
    cout<<"ar: ";
    cin>>ar;
    if(cin.fail())
    {
        cout<<"hibas";
        exit(1);
    }
    cout<<"akcio merteke: ";
    cin>>szazalek;
    if(cin.fail())
    {
        cout<<"hibas";
        exit(1);
    }
    akc=ar*((100-szazalek)/100.0);
    if(szazalek>50)
    {
        szov="megeri";
    }
    else
    {
        szov="nem eri meg";
    }
    cout<<akc<<endl<<szov<<endl;
}
