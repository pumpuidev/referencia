#include <iostream>
#include <cstdlib>
/*Prorok Ernest
Filspa
hbv
ernest.prorok@gmail.com */
using namespace std;

int main()
{
    int szam;
    cout<<"Kerek egy szamot! "<<endl;
    cin>>szam;
    if (szam<=0){
        cout<<"Pozitiv szam legyen!"<<endl;
        exit(1);
    }
    cout<<szam<<"/n";
    return 0;
}
