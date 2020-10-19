
//Feladat:Rank f�le sz�r�s
#include <iostream>

using namespace std;

const int maxN=20,maxM=20; //a k�p m�rete maximum  20*20-es lehet
void letrehozas(int &N,int& M, int K[maxN][maxM]);
void megjelenites(const int N,const int M, const int K[maxN][maxM]);
void szures(const int N,const int M, const int K[maxN][maxM],int KK[maxN][maxM]);

int main()
{
    int N,M; //k�p m�rete
    int K[maxN][maxM],KK[maxN][maxM];
    cout << "Raszteres kep nagyitasa" << endl<<endl;
    letrehozas(N,M,K); //raszteres k�p beolvas�sa - most legener�l�sa v�letlensz�mokkal
    megjelenites(N,M,K); //eredeti m�ret� raszteres k�p megjelen�t�se
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Nagyitott kep"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    szures(N,M,K,KK); //sz�rt v�grehajt�sa
    megjelenites(N,M,KK); //sz�rt k�p megjelen�t�se

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
    for (int i=0;i<N;++i){  // a k�pet v�letlensz�mokkal �ll�tjuk el�, 0-2-ig sz�mo k�br�zolj�k a f�nyess�get
        for (int j=0;j<M;++j){
            K[i][j]=rand()%20;
        }
    }
}
void megjelenites(const int N,const int M, const int K[maxN][maxM]){
 for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
         if (K[i][j]<15){   //a demoban az eredm�ny akkor k�vethet�, ha kev�s maxim�lis f�nyerej� k�ppont van
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
    for (int s1=0;s1<N;++s1){     //A k�p "sz�lei" se vesszenek el.
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
