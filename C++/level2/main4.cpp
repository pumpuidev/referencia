#include <iostream>
#include <vector>
#include <cstdlib> //= #include "stdlib.h"


using namespace std;

int main()
{
    int n;
    cout << "Hany db elem lesz?" << endl;

    bool hiba;
    do{
        cin>>n;
        hiba = cin.fail() || n<0 ;
        if (hiba){
        cin.clear();
        cin.ignore(1000,'\n');
        }
    }
    while(hiba);

    vector<int> t(n);
    for (int i=0;i<t.size();++i){
        do{
            cin>>t[i];
            hiba=cin.fail();
            cin.clear();
            cin.ignore(1000,'\n');
        }
        while(hiba);
    }
    int k=0 ;
    for(int i=0;i<t.size();++i){
        k+=abs(t[i]);
    }
    cout<<"az osszeg: "<<k<<endl;

    return 0;
}
