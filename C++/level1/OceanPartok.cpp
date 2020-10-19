
//Feladat: Tengerfelsz�n feletti magass�gokat t�roljuk.
//Adjuk meg az elso es utolso tengerpontot!
//A t�mb indexeit a 0-N-1 tartom�nyra transzform�ljuk
#include <iostream>

using namespace std;
const int maxN=100;
void beolvasas(int &N,int Mag[]);
void oceanPart(const int N,const int Mag[],int &E,int &U);
void kiiras(const int N,const int Mag[], const int E,const int U);
int main()
{
    int N,E,U;
    int Mag[maxN];                // magass�gokat  tartalmaz� t�mb
    cout<<"Tengerszint feletti magassagokat merunk. Ott mertunk nullat, ahol tenger van. Hol kezdodik es vegzodik az ocean?"<<endl<<endl;
    beolvasas(N,Mag);
    oceanPart(N,Mag,E,U);
    kiiras(N,Mag,E,U);
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
void kiiras(const int N,const int Mag[], const int E,const int U){
    cout<<"A mert magassagok...//0. az elso"<<endl;
    for (int i=0;i<N;++i){
        cout<<Mag[i]<<" ,";
    }
    cout<<endl;
    cout<<"Az elso tengerpont a(z) "<<E<<" helyen"<<endl;
    cout<<"Az utolso tengerpont a(2) "<<U<<" helyen"<<endl;
}

