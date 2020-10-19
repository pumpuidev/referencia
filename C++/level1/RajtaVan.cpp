
//Feladat: Döntsük el, hogy egy potn rajta van-e egy szakaszon
#include <iostream>

using namespace std;
struct pont{       //pont -nak nevezzuk el a pont koordinatait tartalmazo rekordszerkezetet
        float x,y;
    } ;
void beolvaspont(pont &Pontom);
void beolvasas(pont &A,pont &B,pont &C);
int Irany(const pont P,const pont Q);
int Fordul(const pont A,const pont B,const pont C);
bool Kozte(const float A, const float B, const float C);
bool Rajta(const pont A, const pont B, const pont C);
void kiiras(const pont A,const pont B,const pont C,const bool Rajt);
int main()
{
    pont A,B,C;
    bool Rajt;
    cout << "Adott szakaszon rajta van-e egy pont?  " << endl<<endl;
    beolvasas(A,B,C);
    Rajt=Rajta(A,B,C);
    kiiras(A,B,C,Rajt);
    return 0;
}
void beolvaspont(pont &Pontom){
    cout<<"Adja meg az x koordinatat: ";
    cin>>Pontom.x;
    cout<<"Adja meg az y koordinatat: ";
    cin>>Pontom.y;
}
void beolvasas(pont &A,pont &B,pont &C){
    cout<<"Kerem a szakasz vegpontjainak a koordinatait"<<endl;
    cout<<"Az elso pont:"<<endl;
    beolvaspont(A); //a A pont beolvasása
    cout<<"A masodik"<<endl;
    beolvaspont(B); //a B pont beolvasása
    cout<<"Kerem a pont koordinatait"<<endl;
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
bool Kozte(const float A, const float B, const float C){
  return (((A<=C) && (C<=B)) || ((B<=C) && (C<=A)) );
}
bool Rajta(const pont A, const pont B, const pont C){

    return ((Fordul(A,B,C)==0) && Kozte(A.x,B.x,C.x) && Kozte(A.y,B.y,C.y));
}

void kiiras(const pont A,const pont B,const pont C,const bool Rajt){
    cout<<"A szakasz A("<<A.x<< ","<<A.y<<") B("<<B.x<<","<<B.y<<") "<<endl;
    cout<<"A pont C("<<C.x<< ","<<C.y<<")"<<endl;
    if (Rajt) {
        cout<<"A pont rajta van a szakaszon!"<<endl;
    }
    else {
        cout<<"A pont nincs rajta a szakaszon!"<<endl;
    }
}


