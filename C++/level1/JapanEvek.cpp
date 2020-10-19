
//Feladat: A Japánban hagyományos színes évek közé besorolás
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
    }while(!((ev>=1984)&&(ev<=2043)));    //elõfeltétel szerint 1984 és 2043 közé kell
                                         //esnie az évszámnak

    x=(ev-1984)%10;
    y=x/2;

    switch (y){                         //többirányú elágazás, egymást kizáró feltételek
    case    0:s="zold";break;
    case    1:s="piros";break;
    case    2:s="sarga";break;
    case    3:s="feher";break;
    case    4:s="fekete";break;
    };

    cout<<ev<<" Japanban "<<s<<" evnek szamit";

    return 0;
}
