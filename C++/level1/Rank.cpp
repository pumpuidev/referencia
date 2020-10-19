
//Feladat:Rank féle szûrés
#include <iostream>

using namespace std;

const int maxN=20,maxM=20; //a kép mérete maximum  20*20-es lehet
void letrehozas(int &N,int& M, int K[maxN][maxM]);
void megjelenites(const int N,const int M, const int K[maxN][maxM]);
void szures(const int N,const int M, const int K[maxN][maxM],int KK[maxN][maxM]);

int main()
{
    int N,M; //kép mérete
    int K[maxN][maxM],KK[maxN][maxM];
    cout << "Raszteres kep nagyitasa" << endl<<endl;
    letrehozas(N,M,K); //raszteres kép beolvasása - most legenerálása véletlenszámokkal
    megjelenites(N,M,K); //eredeti méretû raszteres kép megjelenítése
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Nagyitott kep"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    szures(N,M,K,KK); //szûrt végrehajtása
    megjelenites(N,M,KK); //szûrt kép megjelenítése

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
    for (int i=0;i<N;++i){  // a képet véletlenszámokkal állítjuk elõ, 0-2-ig számo kábrázolják a fényességet
        for (int j=0;j<M;++j){
            K[i][j]=rand()%20;
        }
    }
}
void megjelenites(const int N,const int M, const int K[maxN][maxM]){
 for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
         if (K[i][j]<15){   //a demoban az eredmény akkor követhetõ, ha kevés maximális fényerejû képpont van
             cout<<" ";
         }
         else {
             if (K[i][j]<19){
                 cout<<".";
             }
             else{
                 cout<<"*";
             }
         }
        }
        cout<<endl;
    }
    };
void szures(const int N,const int M, const int K[maxN][maxM],int KK[maxN][maxM]){
    int max;
    for (int s1=0;s1<N;++s1){     //A kép "szélei" se vesszenek el.
        for (int s2=0;s2<M;++s2){
            KK[s1][s2]=K[s1][s2];
        }
    }
    for (int i=1;i<N-1;++i){
        for (int j=1;j<M-1;++j){
            max=K[i][j];
           for (int p=-1;p<=1;++p){ //szomszedok kozul a legnagyobbat
                for (int q=-1;q<=1;++q){
                    if (K[i+p][j+q]>max){
                        max=K[i+p][j+q];
                    }

                }
           }
           KK[i][j]=max;
        }
    }
}
