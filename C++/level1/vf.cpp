#include <iostream>

using namespace std;
const int nmax=100;
struct TEmber{string Nev; string Szem; string Lakohely;};
bool VF(TEmber ember){
   return ember.Szem[0]=='1' && ember.Lakohely!="Budapest";
}
bool Helyes(int N)
{
   if (N>=nmax){cout<<nmax<<"-nal kisebb";}
   if (N<0) cout<<"Negativ nem lehet\n";
   return (N>=0) && (N<nmax);
}
bool HelyesSzoveg(string s){
  return s!="";
}
void kivalogat(int N, TEmber emberek[nmax],int &Db, int VFI[nmax] ){
   Db=0;
   for (int i=1;i<=N;i++){
      if (VF(emberek[i-1])){
        VFI[Db++]=i;
      }
   }
}
void kiiras(int N, TEmber emberek[nmax],int Db, int VFI[nmax]){
    for (int i=1;i<=Db;i++){
        cout<<emberek[VFI[i-1]-1].Nev<<" "<<emberek[VFI[i-1]-1].Szem<<" "<<emberek[VFI[i-1]-1].Lakohely<<endl;
    }
}
int main()
{
    int N;
    TEmber Emberek[nmax];    int Db;    int VFI[nmax];
    do {
        cerr<<"HAnyan?"; cin>>N;
    }while (!Helyes(N));
    for (int i=1;i<=N;i++){
        do {
            cerr<<"Neve:"; cin>>Emberek[i-1].Nev;
        }while (!HelyesSzoveg(Emberek[i-1].Nev));
         do {
            cerr<<"Szem:"; cin>>Emberek[i-1].Szem;
        }while (!HelyesSzoveg(Emberek[i-1].Szem));
         do {
            cerr<<"Lakohely:"; cin>>Emberek[i-1].Lakohely;
        }while (!HelyesSzoveg(Emberek[i-1].Lakohely));
    }
    kivalogat(N,Emberek,Db,VFI );
    kiiras(N,Emberek,Db,VFI);
    return 0;
}
