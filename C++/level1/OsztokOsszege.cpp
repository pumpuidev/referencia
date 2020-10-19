
//Feladat:   Természetes szám osztóinak az összege
#include <iostream>

using namespace std;

int main()
{
    int N,i,S;

    cout << "Termeszetes szam osztoinak osszege" << endl<<endl;
    do{
        cout<<"Kerek egy termeszetes szamot!"<<endl;
        cin>>N;
    }while (N<=1);  //elõfeltétel szerint N>1

    S=0;
    for (int i=1;i<=N;++i){
        if ((N%i)==0){  //osztoja
            S=S+i;
        }
    }

    cout<<N<<" osztoinak osszege:"<<S<<endl;
    return 0;
}
