
//Feladat: Adjuk meg azoknak a számpároknak a számát, amelyek szorzata
//kisebb egy N termesztes szamnal
#include <iostream>

using namespace std;

int main()
{   int S,N;
    cout<<"Szamparok szama (1-nel nagyobb), amelyek szorzata kisebb egy termeszetes szamnal"<<endl;
    do{
        cout<<"Adja meg a termeszetes szamot";
        cin>>N;
    }while (N<=1) ;  //elõfeltétel szerint N>1

    S=0;
    for (int i=2;i<=N/2;++i){
        for (int j=2;j<=N/2;++j){
            if ((i*j)<N){
                S=S+1;
            }
        }
    }

    cout << "Az " <<N<<"-nel kisebb szorzatot eredmenyezo szamparok szama "<<S<<endl;
    return 0;
}
