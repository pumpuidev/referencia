#include <iostream>

using namespace std;

int main()
{
    const int maxn=100;
    int i,n,ev[maxn];
    bool kisk;
    do{
        cout<<"hany ember volt jelen? (0.."<<maxn<<"): ";
        cin>>n;
    }while(!((n>=0)&&(n<=maxn)));
    for(int i=0;i<n;i++){
        do{
            cout<<i<<". ember szul: ";
            cin>>ev[i];
        }while(!((ev[i]>1900)&&(ev[i]<=2008)));
    }
    i=0;
    while((i<n)&&(ev[i]<=1990)){
        i++;
    }
    kisk=i<n;
    cout<<kisk;
}

