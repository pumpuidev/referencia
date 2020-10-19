#include <iostream>

using namespace std;

int main()
{
    int n,f;
    do{
    cout<<"be fakt";
    cin>>n;
    }while(n<0);
    f=1;
    if(n==0){;;;;;;;}
    else {
        for (int i=1;i<=n;i++){
            f*=i;
        }
    }
    cout<<f<<endl;
    return 0;
}
