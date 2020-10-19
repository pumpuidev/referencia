
//Feladat: Vércsoport meghatározás (3. verzió) - A,B,O
#include <iostream>

using namespace std;

int main()
{
    char x,y;
    string v;
    bool vanA,vanB;
    cout<<"Vercsoport meghatarozasa"<<endl<<endl;
    do {
        cout<<"Kerem a vercsoportot meghatarozo egyik gent (A/B/0):";
        cin>>x;
    }while ((x!='A') && (x!='B')&& (x!='0')); //az elõfeltétel szerint csak A,B vagy 0 lehet
    do {
        cout<<"Kerem a vercsoportot meghatarozo masik gent (A/B/0):";
        cin>>y;
    }while ((y!='A') && (y!='B')&& (y!='0')); //az elõfeltétel szerint csak A,B vagy 0

    vanA=((x=='A')||(y=='A'));
    vanB=((x=='B')||(y=='B'));
    if (vanA){
        if (vanB){
            v="AB";
        }
        else{
            v="A";
        }
    }
    else{
           if (vanB){
            v="B";
        }
        else{
            v="0";
        }
    }

    cout<<v<<" a vercsoportja!"<<endl;
    return 0;
}
