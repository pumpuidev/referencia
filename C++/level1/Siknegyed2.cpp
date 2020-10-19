
//Feladat: határozzuk meg egy pont koordinataibol, hogy melyik siknegyedhez tartozik
#include <iostream>

using namespace std;

struct pont{       //pont -nak nevezzuk el a pont koordinatait tartalmazo rekordszerkezetet
        float x,y;
    } ;
void beolvas(pont &P);
void melyik(const pont P,int &SN);
void kiiras(const pont P,const int SN);
int main()
{
    int SN;
    pont P;
    cout << "Melyik siknegyedhez tartozik egy pont?" << endl<<endl;
    beolvas(P);
    melyik(P,SN);
    kiiras(P,SN);
    return 0;
}
void beolvas(pont &P){
    cout<<"Adja meg az x koordinatat: ";
    cin>>P.x;
    cout<<"Adja meg az y koordinatat: ";
    cin>>P.y;
}
void melyik(const pont P,int &SN){
    if (P.x>=0){
        if (P.y>=0){
            SN=1;
        }
        else{
            SN=4;
        }
    }
    else{
        if (P.y<0){
            SN=3;
        }
        else{
            SN=2;
        }
    }
}
void kiiras(const pont  P,const int SN){
    cout<<"Az x="<<P.x<< " es y="<<P.y<<" koordinataju pont a(z) "<<SN<<" siknegyedbe tartozik"<<endl<<endl;
}
