
//Feladat: Döntsük el, hogy egy pont a háromszögön belül helyezkedik-e el
#include <iostream>

using namespace std;

struct pont{       //pont -nak nevezzuk el a pont koordinatait tartalmazo rekordszerkezetet
        float x,y;
    } ;
void beolvaspont(pont &Pontom);
void beolvasas(pont &A,pont &B,pont &C,pont &D);
int Irany(const pont P,const pont Q);
int Fordul(const pont A,const pont B,const pont C);
bool Belul(const pont A,const pont B,const pont C,const pont D);
void kiiras(const pont A,const pont B,const pont C,const pont C,const bool Bel);
int main()
{
    pont A,B,C,D;
    bool Bel;
    cout << "Adott pont a haromszog belsejeben van-e?  " << endl<<endl;
    beolvasas(A,B,C,D);
    Bel=Belul(A,B,C,D);
    kiiras(A,B,C,D,Bel);
    return 0;
}
void beolvaspont(pont &Pontom){
    cout<<"Adja meg az x koordinatat: ";
    cin>>Pontom.x;
    cout<<"Adja meg az y koordinatat: ";
    cin>>Pontom.y;
}
void beolvasas(pont &A,pont &B,pont &C,pont &D){
    cout<<"Kerem a haromszog csucsainak a koordinatait"<<endl;
    cout<<"Az elso csucs:"<<endl;
    beolvaspont(A); //a A pont beolvasása
    cout<<"A masodik csucs:"<<endl;
    beolvaspont(B); //a B pont beolvasása
    cout<<"A harmadik csucs:"<<endl;
    beolvaspont(C); //a C pont beolvasása
    cout<<"Kerem a pont koordinatait:"<<endl;
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
bool Belul(const pont A,const pont B,const pont C,const pont D){
    return (Fordul(A,B,D)==Fordul(B,C,D))&& (Fordul(B,C,D)==Fordul(C,A,D));
}
void kiiras(const pont A,const pont B,const pont C,const pont D,const bool Bel){
    cout<<"A pont D("<<D.x<< ","<<D.y<<")"<<endl;
    if (Bel) {
        cout<<"A pont a  belsejeben van a "<<endl;
    }
    else {
        cout<<"A pont nincs a belsejeben  a "<<endl;
    }
    cout<<"A("<<A.x<< ","<<A.y<<") B("<<B.x<<","<<B.y<<") C("<<C.x<<","<<C.y<<") pontok altal meghatarozott haromszog" <<endl;


}
