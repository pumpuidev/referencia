
//Feladat:  Természetes szám 1-tõl és önmagától különbözõ osztója, ha van

#include <iostream>

using namespace std;

int main()
{   int N,i,O;
    bool van;
    cout << "Termeszetes szam 1-tol es onmagatol kulonbozo legkisebb osztoja" << endl<<endl;
    do{
        cout<<"Kerek egy termeszetes szamot!"<<endl;
        cin>>N;
    }while (N<=1);  //elõfeltétel szerint N>1

    i=2;
    while ((i<N)&&(N%i)==0){ //elég lenne gyök N-ig
        i=i+1;
    }
    van=i<N;        //i oszto, ha nem az i<N miatt állt le a ciklus

    if (van){
       O=i;
       cout<<"Van megfelelo oszto es ez a "<<O<<endl;
    }
    else{
       cout<<"Nincs megfelelo oszto";
    }

    return 0;
}
