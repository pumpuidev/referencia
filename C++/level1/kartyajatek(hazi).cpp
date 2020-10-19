#include <iostream>

using namespace std;

const int MAXN = 10;

int main()
{string k;
 int e;
 int n;
 const string kartyak[8]={"also", "felso", "kiraly", "asz", "vii", "viii", "ix", "x"};
 const int ertek[8]={2, 3, 4, 11, 7, 8, 9, 10};
 string lapok[MAXN];
 int osszeg=0;

cout << "Hany kartya van a kezedben?  ";
cin >>n;


for ( int j=0; j<n; j++){

 bool hiba;
 do{
    cout << "Milyen kartyak vannak a kezedben?  ";
    cin >> k;
    int i = 0;
    while (i<=8-1 && kartyak[i] != k){
        i++;
    }
    hiba = i>8-1;
    if(hiba){
        cout << "Valami nem jo!" <<endl;
    }
 }while (hiba);
 int i = 0;
 while (kartyak[i]!=k){
    i++;
 }
 osszeg+=ertek[i];
 }
cout << " Ennyi a lapjaid erteke:  "<<osszeg;


    return 0;
}
