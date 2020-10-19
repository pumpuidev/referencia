
//Feladat: Bukott-e és mibõl egy tanuló?
//Keresési tétel
//indextatomany transzformációja az 1..N intervallumról a 0..N-1 tartomanyra
#include <iostream>

using namespace std;
const int maxN=100;
void beolvasas(int &N,int Jegy[]);
void bukas(const int N,const int Jegy[],bool &Van,int &S);
void kiiras(const int N,const int Jegy[],const bool Van,const int S);

int main()
{   int N,S;                        //N tárgy eredményeit tároljuk, S a tárgy sorszáma, amibõl megbukott
    bool Van ;                      //Van-e elégtelen osztályzata
    int Jegy[maxN];                    // jegyek
    cout<<"Bukott-e es mibol"<<endl<<endl;
    beolvasas(N,Jegy);
    bukas(N,Jegy,Van,S);             //
    kiiras(N,Jegy,Van,S);
    return 0;
}
void beolvasas(int &N,int Jegy[]){
    do{
        cout<<"Hany targy eredmenyeit taroljuk (0.."<<maxN<<")?";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //gyerekek szama csak nem negativ lehet
    for (int i=0;i<N;++i){
        do{
            cout<<"Hanyast kapott "<<i<<". targybol (1..5)?"; //a jegyek 1-5 közöttiek
            cin>>Jegy[i];
        }while(!((Jegy[i]<=5)&&(Jegy[i]>=1)));
    }
}
void bukas(const int N,const int Jegy[],bool &Van,int &S){
    int i=0;
    while ((i<N)&&(Jegy[i]!=1)){
        ++i;       //az index transzformált a 0..N-1 intervalllumra
    };
    Van=(i<N);
    if (Van) {
        S=i;
    }
}
void kiiras(const int N,const int Jegy[],const bool Van,const int S){
    cout<<N<<" targybol az eredmenyei:"<<endl;
    for (int i=0;i<N;++i){
        cout<<Jegy[i]<<", ";
    }
    cout<<endl;
    if (Van){
        cout<<"Megbukott a(z) "<<S<<". targybol"<<endl;
    }
    else {
        cout<<"Nem bukott meg!"<<endl;
    }
}
