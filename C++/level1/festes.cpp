
//Feladat: Festes - kitekintes
#include <iostream>

using namespace std;

const int maxN=20,maxM=20; //a kép mérete maximum  20*20-es lehet
const int vilagoskek=1;
const int feher=0;
void letrehozas(const int N,const int M, int K[maxN][maxM]); //N,maxM-es meretu kep
void pontbeolvasas(int &A,int &B);
void megjelenites(const int N,const int M,const int K[maxN][maxM]);
void festes(const int i,const int j, int K[maxN][maxM]);

int main()
{
    int N=maxN,M=maxM; //kép mérete
    int K[maxN][maxM]; //a kép és a beszínezett kép ugyanaban a mátrixban lesz ábrázolva
    int A,B; //kep pontja
    cout << "Raszteres kep belso pontjanak festese" << endl<<endl;
    letrehozas(N,M,K); //raszteres kép beolvasása - most legenerálása véletlenszámokkal
    megjelenites(N,M,K); //eredeti méretû raszteres kép megjelenítése
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Kep belso pontjanak festese"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    pontbeolvasas(A,B);
    festes(A,B,K); //szûrt végrehajtása
    megjelenites(N,M,K); //szûrt kép megjelenítése

    return 0;
}
void letrehozas(const int N,const int M,int K[maxN][maxN]){
    for (int i=0;i<N;++i){  // a képet
        for (int j=0;j<maxM;++j){
            K[i][j]=feher;
        }
    }
    for (int i1=3;i1<=N-3;++i1){
        K[i1][3]=vilagoskek;  // a képet vízszintes vonalak
        K[i1][M-3]=vilagoskek;
    };
    for (int j1=3;j1<=M-3;++j1){ //függõleges vonalak
        K[3][j1]=vilagoskek;
        K[N-3][j1]=vilagoskek;
    }
    for (int i2=6;i2<=N-6;++i2){
        K[i2][6]=vilagoskek;  // a képet vízszintes vonalak
        K[i2][M-6]=vilagoskek;
    };
    for (int j2=6;j2<=M-6;++j2){ //függõleges vonalak
        K[6][j2]=vilagoskek;
        K[N-6][j2]=vilagoskek;
    }
}
void megjelenites(const int N,const int M,const int K[maxN][maxM]){
 for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
         if (K[i][j]==feher){   //a demoban az eredmény akkor követhetõ, ha kevés maximális fényerejû képpont van
            cout<<" ";
         }
         else {
            cout<<"*";
         }
    } cout<<endl;
    };
}
void pontbeolvasas(int &A,int &B){
    cout<<"A kepen a 3. es 6. sorban es oszlopban huztuk be a keretet. Tehat belso pont pl. 10,10.";
    do{
    cout<<"Kerem a pont x koordinatajat (0.."<<maxN<<")";
    cin>>A;
    }while (!((A>=0)&&(A<maxN)));
     do{
    cout<<"Kerem a pont y koordinatajat (0.."<<maxM<<")";
    cin>>B;
    }while (!((B>=0)&&(B<maxM)));
}
void festes(const int i,const int j, int K[maxN][maxM]){
    int max;

        K[i][j]=vilagoskek;
    if (K[i+1][j]==feher){
        festes(i+1,j,K);
        }
    if (K[i][j+1]==feher){
        festes(i,j+1,K);
        }
    if (K[i-1][j]==feher){
        festes(i-1,j,K);
        }
    if (K[i][j-1]==feher){
        festes(i,j-1,K);
    }

}

