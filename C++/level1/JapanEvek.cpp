
//Feladat: A Jap�nban hagyom�nyos sz�nes �vek k�z� besorol�s
#include <iostream>

using namespace std;

int main()
{   int ev,x,y;
    string s;
    cout<<"A Japan naptar jelenlegi 60 eves ciklusa az [1984-2043] kozotti eveket tartalmazza. "<<endl;
    cout<<"Milyen szinu a beolvasott evszam?"<<endl<<endl;
    do{
        cout<<"Melyik ev erdekli? (1984-2043)";
        cin>>ev;
    }while(!((ev>=1984)&&(ev<=2043)));    //el�felt�tel szerint 1984 �s 2043 k�z� kell
                                         //esnie az �vsz�mnak

    x=(ev-1984)%10;
    y=x/2;

    switch (y){                         //t�bbir�ny� el�gaz�s, egym�st kiz�r� felt�telek
    case    0:s="zold";break;
    case    1:s="piros";break;
    case    2:s="sarga";break;
    case    3:s="feher";break;
    case    4:s="fekete";break;
    };

    cout<<ev<<" Japanban "<<s<<" evnek szamit";

    return 0;
}
