#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

int main()
{
    int szamjegy,also,felso,n,i,k,szam;
    bool prim;
    int tomb[1000];
    do {
    cout << "Hany szamjegybol alljon a szam? : ",
    cin >> szamjegy;
    }while(szamjegy<1);
    also=pow(10,szamjegy-1);
    felso=pow(10,szamjegy);
    i=also;
    k=0;

    if (szamjegy>3){
    felso=also+200;}//gyorsabb eredmeny erdekeben

      for(i; i <= felso; i++){
    prim = true;
    for(int n = 2; n < i; n++){
      if(i % n == 0){
        prim = false;
      }
    }
    if(prim){
      cout << i << " primszam" << endl;
      tomb[k]=i;
      k++;
    }
  }
    k=0;
    while((tomb[k]%10)!=1) {
    k++;}
    cout << endl << "A legkisebb 1-re vegzodo prim: " << tomb[k] << endl;
    return 0;
}
