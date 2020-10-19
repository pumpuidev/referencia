
//Feladat: H�nap nev�hez sorsz�m�t rendelj�k
#include <iostream>

using namespace std;
 bool honap_e(string H); //eld�nti, hogy a bevitt adat honap neve-e

int main()
{   string H;
    int S;
    const string Nev[13]={"","januar","februar","marcius","aprilis","majus","junius","julius","augusztus","szeptember","oktober","november","december"};
                        //specifik�ci�ban �s algoritmusban az index 1..12-ig!!

    cout << "Honap nevehez sorszamot rendelunk" << endl<<endl;;
    do{
        cout<<"Kerem a honap nevet (januar,februar,marcius,aprilis,majus,junius,julius,augusztus,szeptember,oktober,november,december)";
        cin>>H;
        }while (!honap_e(H));    //el�felt�tel szerint csak honap nev�t fogadjuk el..

    int i=1;
    while (Nev[i]!=H){
        i++;
    }
    S=i;

    cout<<"A "<<H<<"honap sorszama:"<<S<<endl;
    return 0;
}

bool honap_e(string H){     //eld�nti, hogy a bevitt adat honap neve-e
    int i=1;
    while ((i<=12)&&(Nev[i]!=H)){
        i++;
    };
    return i<=12;            //talalt egyezest, i<=12
}
