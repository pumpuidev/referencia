
//Feladat:  Primoszt�k �sszege
#include <iostream>

using namespace std;

int main()
{   int N,S,i;

    cout << "Termeszetes szam primosztoinak osszege" << endl<<endl;
    do{
        cout<<"Kerek egy termeszetes szamot!"<<endl;
        cin>>N;
    }while (N<=1);  //el�felt�tel szerint N>1

    S=0;
    i=2;
    while (i<=N){
        if ((N%i)==0){ //oszthat�
            S=S+i;
            while ((N%i)==0){
                N=N/i;  //primt�nyez�vel (legkisebb oszt�!!) leosztjuk
            }
        }
        i=i+1;
    }

    cout<<N<<" primosztoinak osszege "<<S<<endl;
    return 0;
}
