
//Feladat: Megadjuk, hogy egy nap az �v h�nyadik napja - szokoevet nem szamolunk
#include <iostream>

using namespace std;

int main()
{   int H,N,S;
    const int Ho[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    cout << "Hanyadik napja az evnek??" << endl<<endl;

    do{
        cout<<"Hanyadik honaprol van szo?(1-12)";
        cin>>H;
    }while (!((H<=12)&&(H>=1)));        //el�felt�tel szerint a honap 1 .. 12 k�z� esik
    do{
        cout<<"Az adott honap hanyadik napjarol van szo?(1-28,30,31)";
        cin>>N;
    }while (!((N<=Ho[H])&&(N>=1))); //el�felt�tel szerint a nap 1 �s Ho[H] k�z� esik

    S=N;
    for(int i=1;i<=H-1;++i){
        S=S+Ho[i];
    }

    cout<<"Az ev elejetol szamitva ez a "<<S<<". napja az evnek"<<endl;

    return 0;
}
