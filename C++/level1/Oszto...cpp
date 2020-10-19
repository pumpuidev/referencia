
//Feladat:  Természetes szám legkisebb 1-tõl különbözõ osztóját és
//önmagától különbözõ legnagyobb osztója
#include <iostream>

using namespace std;

int main()
{   int N,i,LKO,LNO;

    cout << "Termeszetes szam 1-tol kulonbozo legkisebb osztoja" << endl<<endl;
    do{
        cout<<"Kerek egy termeszetes szamot!"<<endl;
        cin>>N;
    }while (N<=1);  //elõfeltétel szerint N>1

    i=2;
    while ((N % i)!=0){
        i=i+1;      //gyorsabb lenne az i++ használata
    }
    LKO=i;
    LNO=N/i;

    cout<<N<<" legkisebb 1-tol kulonbozo osztoja "<<LKO<<endl;
    cout<<N<<" legnagyobb onmagatol kulonbozo osztoja "<<LNO<<endl;

    return 0;
}
