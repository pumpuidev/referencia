#include <iostream>
using namespace std;
const int maxM=1500;
const int maxU=500;
struct Rendeles{
        int X, Y;
};
int halmaz_db(int Matrix[][maxU],int N,int U, int sor);
int main(){
int U, N, M;
Rendeles T[maxM];
cin>>U>>N>>M;
for (int i=0;i<M;++i){
        cin>>T[i].X>>T[i].Y;
}


//kiiras


int temp;
int nap db[300];
for (int i=0; i<N;++i){
        nap_db[i]=0;
}
for (int i=0;i<M;++i){
        temp=T[i].Y;
        nap_db[temp-1]++;
}
int maxi=0;
for (int i=1;i<N;++i){
        if (nap_db[i]>nap_db[maxi]){
                maxi=i;
        }
}
cout<<nap_db[maxi]<<endl;
//2feladat
int db=0;
int b_fel[300];
for (int i=0; i<n;++i){
        if (nap_db[i]>=1;
        db++;)
}
cout<<db<<" ";
for (int i=0;i<db;++i){
        cout <<b_fel[i]+1<<" ";
}cout<<endl;
//cfeladat
int c_fel[U];
for (int=0;i<U;++i){
        c_fel[i]=0;
}
for (int i=0;i<M;++i){
        temp=T[i].X;
        c_fel[temp-1]++;        
}
mixi=0;
for (int i=1; i<U;++i){
        if (c_fel[i]>c_fel[maxi]){
                maxi=i;
        }
}
int maxertek= c_fel[maxi];
int max_indexek[U];
db=0;
for (int i=0; i<db;++i){
        cout<<max_indexek[i]+1<<" ";
}cout<<endl;
//dfeladat
int kezd[N];
int veg[N];
db=0;
for (int i=0; i<N;++i){
        if ((i==0 and nap_db[i]>=1) or (i!=0 and nap_db[i]>=1 and nap_db[i]<1)){
                kezd[db]=i;
        }
        if ((i==N-1 and nap_db[i]>=1) or (i!=N-1 and nap_db[i]>=1 and nap_db[i+1]<1)){
                veg[db]=i+1;
                db++;
        }
}
maxi=0;
for (inti=1; i<db;++i){
        if(veg[i]-kezd[i]>veg[maxi]-kezd[maxi]){
                maxi=i;
        }
}
cout<<kezd[maxi]<<" "<<veg[maxi]<<endl;
//e feladat
maxi=0;
for (int i=1; i<N-1;++i){
        if(nap_db[i]+nap_db[i+1]>nap_db[maxi]+nap_db[maxi+1]){
                maxi=i;
        }
}
cout<<maxi+1<<" "<<maxi+2;
//5 feladat
int Matrix[N][maxU];
for (int i=0;i<N;++i){
        for (int j=0;j<U;++j){
                Matrix[i][j]=-1;
        }
}
for (int i=0; i<N;++i){
        db=0;
        for (int j=0; j<M; ++j){
                if (T[j].Y==i+1){
                        Matrix[i][db]=T[j].X;
                        db++;
                }
        }
}
maxi=0;
for (int i=1;i<N-1;++i){
        if (halmaz_db(Matrix,N,U,i)+halmaz_db(Matrix,N,U,i+1)>halmaz_db(Matrix,N,U,maxi)+halmaz_db(Matrix,N,U,maxi+1)){
                maxi=i;
        }
}
cout<<maxi+1<<" "<<maxi+2;
return 0;}


int halmaz_db(int Matrix[][maxU],int N,int U, int sor){
        int j=0;
        while (j<U and Matrix[sor][j]!=-1){
                j++;
        }
        int k;
        for (int i=0;i<j;++i){
                k=i+1;
                while (k<j and Matrix[sor][i]!=Matrix[sor][k]){
                        k++;
                }
                if (k>=j){
                        db++;
                }
        }
        return db;
}