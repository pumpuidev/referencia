
//Feladat: Kép (raszteres) kicsinyítése
//Az implementáció fekete - fehér kpeket ábrázol - 0 és 1
#include <iostream>

using namespace std;
const int maxN=20,maxM=20; //a nagyitott kép mérete maximum csak 20*20-es lehet
void letrehozas(int &N,int& M, int K[maxN][maxM]);
void megjelenites(const int N,const int M, const int K[maxN][maxM]);
void kicsinyites(const int N,const int M, const int K[maxN][maxM],int NK[maxN][maxM]);

int main()
{
    int N,M; //kép mérete
    int K[maxN][maxM],KK[maxN][maxM];
    cout << "Raszteres kep nagyitasa" << endl<<endl;
    letrehozas(N,M,K); //raszteres kép beolvasása - most legenerálása véletlenszámokkal
    megjelenites(N,M,K); //eredeti méretû raszteres kép megjelenítése
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Kicsinyitett kep"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    kicsinyites(N,M,K,KK); //nagyítás végrehajtása
    megjelenites(N/2,M/2,KK); //nagyított kép megjelenítése

    return 0;
}
void letrehozas(int &N,int& M, int K[maxN][maxN]){
    do{
        cout<<"Mekkora legyen a kep szelessege (1.."<<maxN<<")?";
        cin>>N;
    }while ((N<0)||(N>maxN));
    do{
        cout<<"Mekkora legyen a kep magassaga (1.."<<maxM<<")?";
        cin>>M;
    }while ((M<0)||(M>maxM));
    for (int i=0;i<N;++i){  // a képet véletlenszámokkal állítjuk elõ
        for (int j=0;j<M;++j){
            K[i][j]=rand()%2;
        }
    }
}
void megjelenites(const int N,const int M, const int K[maxN][maxM]){
    //0 helyett spasze-t, 1 helyett *-ot jelenitek meg
 for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
          if (K[i][j]==0){
            cout<<" ";
          }
          else{
              cout<<"*";
          }
        }
        cout<<endl;
    }
    };
void kicsinyites(const int N,const int M, const int K[maxN][maxM],int KK[maxN][maxM]){
    //

    for (int i=0;i<N/2;++i){
        for (int j=0;j<M/2;++j){
            KK[i][j]= (K[2*i][2*j]+K[2*i+1][2*j]+K[2*i][2*j+1]+K[2*i+1][2*j+1]);
            if (KK[i][j]<2){ //ábrázolás miatt vagy 1 vagy 0 a szin értéke
                KK[i][j]=0;
                }
            else{
                    KK[i][j]=1;
            }

        }
    }
}
