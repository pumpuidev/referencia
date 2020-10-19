
//Feladat: Festes - kitekintes
#include <iostream>

using namespace std;

const int maxN=20,maxM=20; //a k�p m�rete maximum  20*20-es lehet
const int vilagoskek=1;
const int feher=0;
void letrehozas(const int N,const int M, int K[maxN][maxM]); //N,maxM-es meretu kep
void pontbeolvasas(int &A,int &B);
void megjelenites(const int N,const int M,const int K[maxN][maxM]);
void festes(const int i,const int j, int K[maxN][maxM]);

int main()
{
    int N=maxN,M=maxM; //k�p m�rete
    int K[maxN][maxM]; //a k�p �s a besz�nezett k�p ugyanaban a m�trixban lesz �br�zolva
    int A,B; //kep pontja
    cout << "Raszteres kep belso pontjanak festese" << endl<<endl;
    letrehozas(N,M,K); //raszteres k�p beolvas�sa - most legener�l�sa v�letlensz�mokkal
    megjelenites(N,M,K); //eredeti m�ret� raszteres k�p megjelen�t�se
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Kep belso pontjanak festese"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    pontbeolvasas(A,B);
    festes(A,B,K); //sz�rt v�grehajt�sa
    megjelenites(N,M,K); //sz�rt k�p megjelen�t�se

    return 0;
}
void letrehozas(const int N,const int M,int K[maxN][maxN]){
    for (int i=0;i<N;++i){  // a k�pet
        for (int j=0;j<maxM;++j){
            K[i][j]=feher;
        }
    }
    for (int i1=3;i1<=N-3;++i1){
        K[i1][3]=vilagoskek;  // a k�pet v�zszintes vonalak
        K[i1][M-3]=vilagoskek;
    };
    for (int j1=3;j1<=M-3;++j1){ //f�gg�leges vonalak
        K[3][j1]=vilagoskek;
        K[N-3][j1]=vilagoskek;
    }
    for (int i2=6;i2<=N-6;++i2){
        K[i2][6]=vilagoskek;  // a k�pet v�zszintes vonalak
        K[i2][M-6]=vilagoskek;
    };
    for (int j2=6;j2<=M-6;++j2){ //f�gg�leges vonalak
        K[6][j2]=vilagoskek;
        K[N-6][j2]=vilagoskek;
    }
}
void megjelenites(const int N,const int M,const int K[maxN][maxM]){
 for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
         if (K[i][j]==feher){   //a demoban az eredm�ny akkor k�vethet�, ha kev�s maxim�lis f�nyerej� k�ppont van
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

