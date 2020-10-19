
//Feladat: Vércsoport meghatározás II. - A,B,O
#include <iostream>

using namespace std;

int main()
{
    char x,y;
    string v;
    cout<<"Vercsoport meghatarozasa"<<endl<<endl;
    do {
        cout<<"Kerem a vercsoportot meghatarozo egyik gent (A/B/0):";
        cin>>x;
    }while ((x!='A') && (x!='B')&& (x!='0')); //az elõfeltétel szerint csak A,B vagy 0 lehet
    do {
        cout<<"Kerem a vercsoportot meghatarozo masik gent (A/B/0):";
        cin>>y;
    }while ((y!='A') && (y!='B')&& (y!='0')); //az elõfeltétel szerint csak A,B vagy 0

    if (((x=='A')&&(y!='B'))||((x!='B')&&(y=='A'))){       //az A és B domináns gén
        v="A";
    }
    else{
        if ((((x=='B')&&(y!='A'))||((x!='A')&&(y=='B')))){ //az A és B domináns gén
            v="B";
        }
        else{
            if ((((x=='B')&&(y=='A'))||((x=='A')&&(y=='B')))){
            v="AB";
            }
            else{
                v="0";
            }
        }
    }

    cout<<v<<" a vercsoportja!"<<endl;
    return 0;
}
