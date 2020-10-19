
//Feladat: AB szakaszhoz képest jobbra vagy balra van-e a C pont
#include <iostream>

using namespace std;

struct pont{       //pont -nak nevezzuk el a pont koordinatait tartalmazo rekordszerkezetet
        float x,y;
    } ;
void beolvaspont(pont &Pontom);
void beolvasas(pont &A,pont &B,pont &C);
int Irany(const pont P,const pont Q);
int Fordul(const pont A,const pont B,const pont C);
void kiiras(const pont  A,const pont B,const pont C,const int Ford);
int main()
{
    pont A,B,C; //AB szakasz, C pont
    int Ford;
    cout << "Adott szakasztol balra vagy jobbra van-e egy pont?  " << endl<<endl;
    beolvasas(A,B,C);
    Ford=Fordul(A,B,C);
    kiiras(A,B,C,Ford);
    return 0;
}
void beolvaspont(pont &P){
    cout<<"Adja meg az x koordinatat: ";
    cin>>P.x;
    cout<<"Adja meg az y koordinatat: ";
    cin>>P.y;
}
void beolvasas(pont &A,pont &B,pont &C){
    cout<<"Adja meg a szakasz vegpontjainak koordinatajat!"<<endl;
    beolvaspont(A); //az A pont beolvasása
    beolvaspont(B); //a B pont beolvasása
    cout<<"Kerem adja meg a pont koordinatait"<<endl;
    beolvaspont(C); //a C pont beolvasása
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
int Fordul(const pont A,const pont B,const pont C){
    pont P,Q; //eltoljuk a pontokat úgy, hogy A az origoba kerüljön.
    P.x=B.x-A.x; //B-t eltoltuk
    P.y=B.y-A.y;
    Q.x=C.x-A.x; //C-t eltoltuk
    Q.y=C.y-A.y;
    return Irany(P,Q); //pontok iránya egymáshoz képest
}
void kiiras(const pont  A,const pont B,const pont C,const int Ford){
    cout<<"Az AB szakaszhoz A("<<A.x<< ","<<A.y<<") B("<<B.x<<","<<B.y<<") kepest a C("<<C.x<<","<<C.y<<") koordinataju pont"<<endl;
    switch (Ford){
     case   -1: cout<<"balra ";break;
     case    0: cout<<"ugyanabban az iranyban ";break;
     default: cout<<"jobbra ";
    }
    cout<<"van.";
}

