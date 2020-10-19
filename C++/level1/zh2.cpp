#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string nevek[n];
    int mennyisegek[n];
    for (int i=0; i<n; ++i){
        cout<<"kerem neveket"<<endl;
        cin>>nevek[i];
        cout<<i<<". menny.-et"<<endl;
        cin>>mennyisegek[i];
    }
    int i=0;
    while (i<n && mennyisegek[i]!=1){
        ++i;
    }
    bool felt=(i == n-1);
    if (felt){
        cout<<"van alapanyag";
    }else{cout<<"nincs olyan alapanyag";}

    int min=mennyisegek[0];
    for (int i=1; i<n; ++i){
        if (mennyisegek[i]<min){
            min=mennyisegek[i];
        }
    }
cout<<"legkisebb "<<min<<endl;


    return 0;
}
