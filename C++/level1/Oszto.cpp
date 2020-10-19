
//Feladat:  Primosztók összege
#include <iostream>

using namespace std;

int main()
{   int N,S,i;

    cout << "Termeszetes szam primosztoinak osszege" << endl<<endl;
    do{
        cout<<"Kerek egy termeszetes szamot!"<<endl;
        cin>>N;
    }while (N<=1);  //elõfeltétel szerint N>1

    S=0;
    i=2;
    while (i<=N){
        if ((N%i)==0){ //osztható
            S=S+i;
            while ((N%i)==0){
                N=N/i;  //primtényezõvel (legkisebb osztó!!) leosztjuk
            }
        }
        i=i+1;
    }

    cout<<N<<" primosztoinak osszege "<<S<<endl;
    return 0;
}
