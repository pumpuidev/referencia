
//Feladat:Metszi-e egymást két szakasz
#include <iostream>

using namespace std;
struct pont{       //pont -nak nevezzuk el a pont koordinatait tartalmazo rekordszerkezetet
        float x,y;
    } ;
void beolvaspont(pont &Pontom);
void beolvasas(pont &A,pont &B,pont &C,pont &D);
int Irany(const pont P,const pont Q);
int Fordul(const pont A,const pont B,const pont C);
bool Kozte(const float A, const float B, const float C);
bool Rajta(const pont A, const pont B, const pont C);
bool Metszi(const pont A,const pont B,const pont C,const pont D);
void kiiras(const pont A,const pont B,const pont C,const pont D,const bool Metsz);
int main()
{
    pont A,B,C,D;
    bool Metsz;
    cout << "Adott szakaszok metszik-e egymast?  " << endl<<endl;
    beolvasas(A,B,C,D);
    Metsz=Metszi(A,B,C,D);
    kiiras(A,B,C,D,Metsz);
    return 0;
}
void beolvaspont(pont &Pontom){
    cout<<"Adja meg az x koordinatat: ";
    cin>>Pontom.x;
    cout<<"Adja meg az y koordinatat: ";
    cin>>Pontom.y;
}
void beolvasas(pont &A,pont &B,pont &C,pont &D){
    cout<<"Kerem az elso szakasz vegpontjainak a koordinatait"<<endl;
    cout<<"Az elso pont:"<<endl;
    beolvaspont(A); //a A pont beolvasása
    cout<<"A masodik"<<endl;
    beolvaspont(B); //a B pont beolvasása
    cout<<"Kerem az masodik szakasz vegpontjainak a koordinatait"<<endl;
    cout<<"Az elso pont:"<<endl;
    beolvaspont(C); //a C pont beolvasása
    cout<<"A masodik"<<endl;
    beolvaspont(D); //a D pont beolvasása
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
bool Metszi(const pont A,const pont B,const pont C,const pont D){
    int fabc=Fordul(A,B,C);
    int fabd=Fordul(A,B,D);
    int fcda=Fordul(C,D,A);
    int fcdb=Fordul(C,D,B);
    cout<<fabc<<" "<<fabd<<","<<fcda<<" "<<fcdb<<endl;
    return ((((fabc*fabd)<0)&&((fcda*fcdb)<0)) || Rajta(A,B,C) || Rajta(A,B,D)||Rajta(C,D,A)||Rajta(C,D,B));
}
void kiiras(const pont A,const pont B,const pont C,const pont D,const bool Metsz){
    cout<<"Az egyik szakasz A("<<A.x<< ","<<A.y<<") B("<<B.x<<","<<B.y<<") "<<endl;
    cout<<"A masik szakasz C("<<C.x<< ","<<C.y<<") D("<<D.x<<","<<D.y<<") "<<endl;
    if (Metsz) {
        cout<<"A ket szakasz metszi egymast!"<<endl;
    }
    else {
        cout<<"A ket szakasz nem metszi egymast!"<<endl;
    }
}


