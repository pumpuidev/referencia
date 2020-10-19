#include <iostream>

using namespace std;

const int maxN=100;


void beolvas(int&N,int MegB[])
{
    do
    {
        cout<<"Ennyi adat: ";
        cin>>N;
    }while(!((N>=0)&&(N<maxN)));
    for(int i=0;i<N;++i)
    {
        cout<<i<<". adat: ";
        cin>>MegB[i];
    }
}

void maximum(int&Max,int N,int MegB[])
{
    Max=1;
    for(int i=2;i<N;++i)
    {
        if(MegB[Max]<MegB[i])
        {
            Max=i;
        }
    }
}

void min1000(bool&Van,int N,int MegB[],int i)
{
    i=1;
    while((i<=N)&&(MegB[i]<1000))
    {
        ++i;
    }
    Van=i<=N;
}

void osszeg(int&ossz,int N,int MegB[])
{
    ossz=0;
    for(int j=0;j<N;++j)
    {
        ossz=ossz+MegB[j];
    }
}

void kiiras(const int Max,const int MegB[],const int Van,const int ossz)
{
    cout<<"max megbetegedes hete: "<<Max<<endl;
    cout<<"max megbetegedes szama: "<<MegB[Max]<<endl;
    cout<<"1000-nel nagyobb: "<<Van<<endl;
    cout<<"osszeg: "<<ossz<<endl;
}

int main()
{
    int i;
    int N;
    int MegB[maxN];
    int Max;
    bool Van;
    int ossz;
    beolvas(N,MegB);
    maximum(Max,N,MegB);
    min1000(Van,N,MegB,i);
    osszeg(ossz,N,MegB);
    kiiras(Max,MegB,Van,ossz);
}
