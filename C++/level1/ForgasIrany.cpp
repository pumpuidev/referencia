
//Feladat: P ponttól balra vagy jobbra van-e Q
#include <iostream>

using namespace std;

struct pont{       //pont -nak nevezzuk el a pont koordinatait tartalmazo rekordszerkezetet
        float x,y;
    } ;
void beolvaspont(pont &Pontom);
void beolvasas(pont &P,pont &Q);
int Irany(const pont P,const pont Q);
void kiiras(const pont P,const pont Q,const int Ir);
int main()
{
    pont P,Q;
    int Ir;
    cout << "Adott ponttol balra vagy jobbra van-e a masik?  " << endl<<endl;
    beolvasas(P,Q);
    Ir=Irany(P,Q);
    kiiras(P,Q,Ir);
    return 0;
}
void beolvaspont(pont &P){
    cout<<"Adja meg az x koordinatat: ";
    cin>>P.x;
    cout<<"Adja meg az y koordinatat: ";
    cin>>P.y;
}
void beolvasas(pont &P,pont &Q){
    cout<<"Kerem a pontok kordinatait"<<endl;
    cout<<"Az elso pont:"<<endl;
    beolvaspont(P); //a P pont beolvasása
    cout<<"A masodik"<<endl;
    beolvaspont(Q); //a Q pont beolvasása
}
int Irany(const pont P,const pont Q){
    int F;
    float S;
    S=P.y*Q.x-Q.y*P.x;
    if (S<0){
        F=-1;
    }
    else{
        if (S==0){
            F=0;
        }
        else{
            F=1;
        }
    }
        return F;
}
void kiiras(const pont  P,const pont Q,const int Ir){
    cout<<"Az x=("<<P.x<< ","<<P.y<<") ponthoz kepest az y=("<<Q.x<<","<<Q.y<<") koordinataju pont"<<endl;
    switch (Ir){
     case   -1: cout<<"balra ";break;
     case    0: cout<<"ugyanabban az iranyban ";break;
     default: cout<<"jobbra ";
    }
    cout<<"van.";
}

