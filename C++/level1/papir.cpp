#include <iostream>

using namespace std;

int main()
{
    const int maxn=100;
    int n;
    float papir[maxn],osszesen;
    do{
        cout<<"hany ember gyujtott papirt? (0.."<<maxn<<"): ";
        cin>>n;
    }while(!((n>=0)&&(n<=maxn)));
    for(int i=0;i<n;i++){
        do{
            cout<<i<<". ember altal gyujtott papir mennyisege: ";
            cin>>papir[i];
        }while(!(papir[i]>=0));
    }
    osszesen=0.0;
    for(int j=0;j<n;j++){
        osszesen=osszesen+papir[j];
    }
    cout<<"osszes papir: "<<osszesen;
}
