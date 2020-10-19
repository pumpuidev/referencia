
//Feladat: Tengerfelsz�n feletti magass�gokat t�roljuk.
//Adjuk meg a szigeteket!
#include <iostream>

using namespace std;
const int maxN=100;
void beolvasas(int &N,int Mag[]);
void oceanPart(const int N,const int Mag[],int &E,int &U);
void szigetek(const int  N,const int Mag[],int &Db,int K[],int V[]);
void kiiras(const int N,const int Mag[], const int Db,const int K[],const int V[]);
bool szigetKezdet(const int i,const int Mag[]);
bool szigetVeg(const int i,const int Mag[]);
int main()
{
    int N,Db;
    int Mag[maxN],K[maxN],V[maxN];                // magass�gokat  tartalmaz� t�mb
    cout<<"Tengerszint feletti magassagokat merunk. Ott mertunk nullat, ahol tenger van. Hol kezdodik es vegzodik az ocean?"<<endl<<endl;
    beolvasas(N,Mag);
    szigetek(N,Mag,Db,K,V);
    kiiras(N,Mag,Db,K,V);
    return 0;
}
void beolvasas(int &N,int Mag[]){
    bool voltMarViz=false;
    do{
        cout<<"Hanyszor mertunk? (3.."<<maxN<<")";
        cin>>N;
    }while (!((N>=3)&&(N<=maxN)));  //meresek szama legal�bb 3 -
                                    //k�t pozit�v �s legal�bb egy nulla pont!
    do {
        cout<<0<<". meres (0<)";
        cin>>Mag[0];
    }while (!(Mag[0]>0));                 //els� m�r�s csak pozit�v lehet
    do{
        cout<<"Legalabb 1 tengerpontnak is kell lennie! "<<endl;
        for (int i=1;i<N-1;++i){
            do{
                cout<<i<<". meres (0<=)";
                cin>>Mag[i];
                if (Mag[i]==0){
                    voltMarViz=true;
                }
            }while(!(Mag[i]>=0));        //meresek erteke nem negat�v
        }
    } while (!voltMarViz);          //el�felt�tel szerint kell viznek lenni!!!
    do {                            //utols� m�r�s csak pozit�v lehet
        cout<<N-1<<". meres (0<)";
        cin>>Mag[N-1];
    }while(!(Mag[N-1]>0));
}
void oceanPart(const int N,const int Mag[],int &E,int &U){
    E=1;
    while (Mag[E]>0){
        ++E;
    }
    U=N-1;
    while (Mag[U]>0){
        --U;
    }

}
void szigetek(const int N,const int Mag[],int &Db,int K[],int V[]){
    int E,U;
    oceanPart(N,Mag,E,U);  //specifik�ci� szerint �ce�n kezd� �s v�ge k�z�tt
    Db=0;
    for (int i=E;i<U;++i){
        if (szigetKezdet(i,Mag)){
            ++Db;
            K[Db-1]=i;  //null�t�l kezd�dik az index
        }
        if (szigetVeg(i,Mag)){
            V[Db-1]=i;
        }
    }
}
void kiiras(const int N,const int Mag[], const int Db,const int K[],const int V[]){
    cout<<"A mert magassagok...//0. az elso"<<endl;
    for (int i=0;i<N;++i){
        cout<<Mag[i]<<" ,";
    }
    cout<<endl;
    cout<<Db<< " darab sziget van"<<endl;
    for (int j=0;j<Db;++j){
        cout<<"Az "<<j<<". sziget eleje: "<<K[j]<<endl;
        cout<<"Az "<<j<<". sziget vege: "<<V[j]<<endl;
    }
}
bool szigetKezdet(const int i,const int Mag[]){
        return ((Mag[i]==0) && (Mag[i+1]>0));
};

bool szigetVeg(const int i,const int Mag[]){
    return ((Mag[i]>0) && (Mag[i+1]==0));
}
