
//Feladat: 1 �s 99 k�z�tti eg�sz sz�m ki�r�sa bet�vel
#include <iostream>

using namespace std;

int main()
{   int N;
    string s;
    const string egyesek[10]={"","egy","ketto","harom","negy","ot","hat","het","nyolc","kilenc"};
    const string tizesek[10]={"","tizen","huszon","harminc","negyven","otven","hatvan","hetven","nyolcvan","kilencven"};
    cout<<"1 es 99 kozotti szamok kiirasa betuvel"<<endl<<endl;
    do{
        cout<<"Kerem az egesz szamot (1...99) ";
        cin>>N;
    }while(!((N>=1)&&(N<=99)));

    switch (N){
        case 10: s="tiz";break;
        case 20: s="husz";break;
        default: s=tizesek[N/10]+egyesek[N %10];
    }

    cout <<N<<" erteke betukkel kiirva: "<<s<<endl;
    return 0;
}
