
#include <iostream>

using namespace std;

int main()
{
    const int AtvaltDb=5;
    const int Atvaltas[AtvaltDb]={7*24*60*60,24*60*60,60*60,60,1};
    const string Me[AtvaltDb]={"het","nap","ora","perc","masodperc"};
    int Idotartam;
    int Idok[AtvaltDb];

    do
    {
        cout<<"Adjon meg egy idotartamot masodpercben (>=0): ";
        cin>>Idotartam;
    }while(!(Idotartam>=0));

    for(int i=0;i<AtvaltDb;++i)
    {
        Idok[i]=Idotartam/Atvaltas[i];
        Idotartam=Idotartam-Idok[i]*Atvaltas[i];
    }

    cout<<"Atszamolva: ";
    for(int j=0;j<=(AtvaltDb-1);++j)
    {
        if(Idok[j]>0)
        {
            cout<<Idok[j]<<" "<<Me[j]<<", ";
        }
    }
    cout<<endl;
}
