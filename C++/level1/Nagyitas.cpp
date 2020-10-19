
//Feladat: Raszter kép nagyítása a kétszeresére
// A raszteres képet egy véletlenszámokkal feltöltött mátrix-szal fogjuk demonstrálni
#include <iostream>

using namespace std;
const int maxN=10,maxM=10; //a nagyitott kép mérete maximum csak 20*20-es lehet
void letrehozas(int &N,int& M, int K[2*maxN][2*maxM]);
void megjelenites(const int N,const int M, const int K[2*maxN][2*maxM]);
void nagyitas(const int N,const int M, const int K[2*maxN][2*maxM],int NK[2*maxN][2*maxM]);

int main()
{
    int N,M; //kép mérete
    int K[2*maxN][2*maxM],NK[2*maxN][2*maxM];
    cout << "Raszteres kep nagyitasa" << endl<<endl;
    letrehozas(N,M,K); //raszteres kép beolvasása - most legenerálása véletlenszámokkal
    megjelenites(N,M,K); //eredeti méretû raszteres kép megjelenítése
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Nagyitott kep"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    nagyitas(N,M,K,NK); //nagyítás végrehajtása
    megjelenites(2*N,2*M,NK); //nagyított kép megjelenítése

    return 0;
}
void letrehozas(int &N,int& M, int K[2*maxN][2*maxN]){
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
void megjelenites(const int N,const int M, const int K[2*maxN][2*maxM]){
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
void nagyitas(const int N,const int M, const int K[2*maxN][2*maxM],int NK[2*maxN][2*maxM]){
    for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
            NK[2*i][2*j]=K[i][j];
            NK[2*i+1][2*j]=K[i][j];
            NK[2*i+1][2*j+1]=K[i][j];
            NK[2*i][2*j+1]=K[i][j];
        }
    }
}
