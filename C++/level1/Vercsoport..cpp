
//Feladat: Vércsoport meghatározás RH+ vagy RH-
#include <iostream>

using namespace std;

int main()
{
    char x,y;
    string v;
    cout<<"Vercsoport meghatarozasa"<<endl<<endl;
    do {
        cout<<"Kerem a vercsoportot meghatarozo egyik gent (+/-):";
        cin>>x;
    }while ((x!='+') && (x!='-')); //az elõfeltétel szerint csak + vagy -
    do {
        cout<<"Kerem a vercsoportot meghatarozo masik gent (+/-):";
        cin>>y;
    }while ((y!='+') && (y!='-')); //az elõfeltétel szerint csak + vagy -

    if ((x=='+')||(y=='+')){       //a + a domináns gén
        v="RH+ a vercsoportja";
    }
    else{
        v="RH- a vercsoportja";
    }

    cout<<v<<endl;
    return 0;
}
