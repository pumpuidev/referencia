
//Feladat: V�rcsoport meghat�roz�s RH+ vagy RH-
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
    }while ((x!='+') && (x!='-')); //az el�felt�tel szerint csak + vagy -
    do {
        cout<<"Kerem a vercsoportot meghatarozo masik gent (+/-):";
        cin>>y;
    }while ((y!='+') && (y!='-')); //az el�felt�tel szerint csak + vagy -

    if ((x=='+')||(y=='+')){       //a + a domin�ns g�n
        v="RH+ a vercsoportja";
    }
    else{
        v="RH- a vercsoportja";
    }

    cout<<v<<endl;
    return 0;
}
