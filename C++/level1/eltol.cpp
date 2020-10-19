#include <iostream>

using namespace std;

void beolvasas(int&n,int x[])
{
    cout<<"Hany: ";
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
        cout<<i<<". elem: ";
        cin>>x[i];
    }
}

void eltol(const int n,int x[])
{
    int seged=x[0];
    for(int i=0;i<n-1;i++)
    {
        x[i]=x[i+1];
    }
    x[n-1]=seged;
}

void kiiras(const int n,const int x[])
{
    cout<<n<<" elemu tomb eltolva"<<endl;
    for(int i=0;i<=n-1;i++)
    {
        cout<<x[i]<<", ";
    }
}

int main()
{
    int n;
    int x[100];
    beolvasas(n,x);
    eltol(n,x);
    kiiras(n,x);
}
