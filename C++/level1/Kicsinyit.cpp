
//Feladat: K�p (raszteres) kicsiny�t�se
//Az implement�ci� fekete - feh�r kpeket �br�zol - 0 �s 1
#include <iostream>

using namespace std;
const int maxN=20,maxM=20; //a nagyitott k�p m�rete maximum csak 20*20-es lehet
void letrehozas(int &N,int& M, int K[maxN][maxM]);
void megjelenites(const int N,const int M, const int K[maxN][maxM]);
void kicsinyites(const int N,const int M, const int K[maxN][maxM],int NK[maxN][maxM]);

int main()
{
    int N,M; //k�p m�rete
    int K[maxN][maxM],KK[maxN][maxM];
    cout << "Raszteres kep nagyitasa" << endl<<endl;
    letrehozas(N,M,K); //raszteres k�p beolvas�sa - most legener�l�sa v�letlensz�mokkal
    megjelenites(N,M,K); //eredeti m�ret� raszteres k�p megjelen�t�se
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Kicsinyitett kep"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    kicsinyites(N,M,K,KK); //nagy�t�s v�grehajt�sa
    megjelenites(N/2,M/2,KK); //nagy�tott k�p megjelen�t�se

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
    for (int i=0;i<N;++i){  // a k�pet v�letlensz�mokkal �ll�tjuk el�
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
            if (KK[i][j]<2){ //�br�zol�s miatt vagy 1 vagy 0 a szin �rt�ke
                KK[i][j]=0;
                }
            else{
                    KK[i][j]=1;
            }

        }
    }
}
