
//Feladat:  A Jap�nban hagyom�nyos sz�nes �vek k�z� besorol�s - t�mb�s megold�s
#include <iostream>

using namespace std;

int main()
{ int ev,x,y;
  const string Szin[5]={"zold","piros","sarga","feher","fekete"};
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
    s=Szin[y];

    cout<<ev<<" Japanban "<<s<<" evnek szamit"<<endl;

    return 0;
}
