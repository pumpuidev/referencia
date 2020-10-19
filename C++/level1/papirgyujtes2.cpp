#include <iostream>

using namespace std;
const int Nmax=100;
bool Helyes(int N){
    if(N>=Nmax){
    cout<<"Nmax-nal kisebb";
    }
    if (N<0){cout<<"Negativ N nem lehet\n";}
    return (N>=0) && (N<Nmax);}
bool HelyesP(float P){
    if(P<=0){cout<<"Negatiy vagy nulla nem lehet\n";}
    return P>0;}
int main()
{
    int N;
    float Papir[Nmax];
    float Osszeg;

    do {
        cout<<"Hanyan hoztak?";
        cin>>N;
    }while(!Helyes(N));
    for (int i=1;i<=N;i++){
        do{ //ez g'jo
            cout<<i<<". gyerek mennyit?";
            cin>>Papir[i-1];
        }while(!HelyesP(Papir[i-1]));
    }

    Osszeg=0;
    for(int i=1;i<=N;i++){
        Osszeg+=Papir[i-1];
    }
    cout<<Osszeg<<endl;
    return 0;
}
