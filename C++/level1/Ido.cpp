
//Feladat: Földrengések között eltelt másodperceket adjuk meg

#include <iostream>

using namespace std;
const int maxN=100;
struct Ido{
   int O,P,M; //ora, perc, másodperc
};
void beolvasas(int &N,Ido R[maxN]);
void szamitas(const int N,const Ido R[maxN],int T[maxN-1]);
void kiiras(const int N,const Ido R[maxN],const int T[maxN-1]);
int main()
{
    int N; //rengések száma
    Ido R[maxN]; //rengések tömbje, amelyik rekordokat tartalmaz
    int T[maxN-1]; //rengések között eltelt idõ
    cout << "Rengesek kozott eltelt ido" << endl<<endl;
    beolvasas(N,R);
    szamitas(N,R,T);
    kiiras(N,R,T);

    return 0;
}
void beolvasas(int &N,Ido R[maxN]){
    do {
        cout<<"Hany rengest mertek? (1.."<<maxN<<")";
        cin>>N;
    }while(!((N<maxN)&&(N>0)));
    for (int i=0;i<N;++i){
        do{
            cout<<"Kerem az "<<i<<". idopontot! ora:";
            cin>>R[i].O; //i.idopont (ez egy rekord) O mezõje
        } while (!((R[i].O>=0)&&(R[i].O<24)));
        do{
            cout<<"perc:";
            cin>>R[i].P; //i.idopont (ez egy rekord) O mezõje
        } while (!((R[i].P>=0)&&(R[i].P<60)));
        do{
            cout<<"masodperc:";
            cin>>R[i].M; //i.idopont (ez egy rekord) O mezõje
        } while (!((R[i].M>=0)&&(R[i].M<60)));
    }
}

void szamitas(const int N,const Ido R[maxN],int T[maxN-1]){
    int S[maxN];
    for (int i=0;i<N;++i){
        S[i]=R[i].O*3600+R[i].P*60+R[i].M;
    };
    for (int i1=0;i1<N-1;++i1){
        T[i1]=S[i1+1]-S[i1];
    };
};
void kiiras(const int N,const Ido R[maxN],const int T[maxN-1]){
    int O,P,M;
    cout<<"A rengesek ideje:"<<endl;
    for (int i=0;i<N;++i){
        cout<<R[i].O<<":"<<R[i].P<<":"<<R[i].M<<endl;
    };
    cout<<"Az idokulonbsegek masodpercben:"<<endl;
    for (int i1=0;i1<N-1;++i1){
        O=T[i1]/3600;
        P=(T[i1]-O*3600)/60;
        M=T[i1]-O*3600-P*60;
        cout<<T[i1]<<" masodperc - "<<O<<":"<<P<<":"<<M<<endl;
    };
    cout<<endl;
};
