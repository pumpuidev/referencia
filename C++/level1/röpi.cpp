#include <iostream>
#include <math.h>

using namespace std;
struct tzh{
   int ropi;
   int cs1;
   int cs2;
   int evf;
};
const int nmax=100;
void beolvasas(int &N,tzh jegyek[nmax]){
   cin>>N; //cerr<<N;
   for (int i=1;i<=N;i++){
      cin>>jegyek[i-1].ropi>>jegyek[i-1].cs1>>jegyek[i-1].cs2>>jegyek[i-1].evf;
      //cerr<<jegyek[i-1].ropi<<" "<<jegyek[i-1].cs1<<" "<<jegyek[i-1].cs2<<" "<<jegyek[i-1].evf<<endl;;

   }
}
int megszamolas(int N,tzh jegyek[nmax]){
  int db=0;
  for (int i=1;i<=N;i++){
        if (jegyek[i-1].ropi<10) db++;
  }
  return db;
}
void kivalogatas(int N,tzh jegyek[nmax]){
   int db=0;
   int index[nmax];
    for (int i=1;i<=N;i++){
        if ((jegyek[i-1].ropi>9)&&
            (jegyek[i-1].cs1==0 || jegyek[i-1].cs2==0 || jegyek[i-1].evf==0))
            index[db++]=i;
    }
    cout<<db<<" ";
    for (int i=1;i<=db;i++){
        cout<<index[i-1]<<" ";
    }
}
int gyakjegy(int r,int cs1,int cs2,int evf){
   int gyj;
   if (r<10) {gyj=1;} else {
      gyj=floor((cs1+cs2+2*evf)/4 +0.5);
      if (gyj<1) gyj=1;
   }
   return gyj;
}
bool jobblenne(int r,int cs1,int cs2,int evf){
  int gy1,gy2,gy3,gy4,gy5;
  gy1=gyakjegy(r,cs1,cs2,evf);
  if (r<20)  gy2=gyakjegy(r+1,cs1,cs2,evf); else gy2=gyakjegy(r,cs1,cs2,evf);
  if (cs1<5)  gy3=gyakjegy(r,cs1+1,cs2,evf); else gy3=gyakjegy(r,cs1,cs2,evf);
  if (cs2<5)  gy4=gyakjegy(r,cs1,cs2+1,evf); else gy4=gyakjegy(r,cs1,cs2,evf);
  if (evf<5) gy5=gyakjegy(r,cs1,cs2,evf+1); else gy4=gyakjegy(r,cs1,cs2,evf);
  return (gy1<gy2) || (gy1<gy3) || (gy1<gy4) || (gy1<gy5);
}
void keres(int N,tzh jegyek[nmax]){
  int i=1;
  while ((i<=N)&&(jobblenne(jegyek[i-1].ropi,jegyek[i-1].cs1,jegyek[i-1].cs2,jegyek[i-1].evf)))
    i++;
  if (i>=N) {cout<<0<<endl;}
  else {cout<<i<<endl;}
}

int main()
{
    int N;
    tzh jegyek[nmax];
    beolvasas(N,jegyek);
    cout<<megszamolas(N,jegyek)<<endl;
    kivalogatas(N,jegyek); cout<<endl;
    keres(N,jegyek);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    return 0;
}
