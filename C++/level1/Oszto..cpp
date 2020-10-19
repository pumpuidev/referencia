
//Feladat:  Természetes szám legkisebb 1-tõl különbözõ osztóját
#include <iostream>

using namespace std;

int main()
{   int N,i,O;

    cout << "Termeszetes szam 1-tol kulonbozo legkisebb osztoja" << endl<<endl;
    do{
        cout<<"Kerek egy termeszetes szamot!"<<endl;
        cin>>N;
    }while (N<=1);  //elõfeltétel szerint N>1

    i=2;
    while ((N % i)!=0){
        i=i+1;      //gyorsabb lenne az i++ használata
    }
    O=i;

    cout<<N<<" legkisebb 1-tol kulonbozo osztoja "<<O<<endl;

    return 0;
}
