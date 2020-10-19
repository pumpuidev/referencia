#include <iostream>

using namespace std;

const int maxN=100;
void beolvas(int&N,string Zenekar[]);
bool Vanferfi(const int N,const string Zenekar[]);
void kiiras(const int N,const string Zenekar[],const bool Vanf);
bool ferfi(string akt);

int main()
{
    int N;
    string Zenekar[maxN];
    bool Vanf;
    beolvas(N,Zenekar);
    Vanf=Vanferfi(N,Zenekar);
    kiiras(N,Zenekar,Vanf);
}

void beolvas(int&N,string Zenekar[])
{
    do
    {
        cout<<"Hany tagja: ";
        cin>>N;
    }while(!((N>=0)&&(N<maxN)));
    for(int i=0;i<N;++i)
    {
        cout<<i<<". elem: ";
        cin>>Zenekar[i];
    }
}

bool Vanferfi(const int N,const string Zenekar[])
{
    int i=0;
    while((i<N)&&!ferfi(Zenekar[i]))
    {
        ++i;
    }
    return(i<N);
}

bool ferfi(string akt)
{
    return akt[0]=='1';
}

void kiiras(const int N,const string Zenekar[],const bool Vanf)
{
    cout<<N<<" tagu zenekar"<<endl;
    for(int i=0;i<N;++i)
    {
        cout<<Zenekar[i]<<", "<<endl;
    }
    if(Vanf)
    {
        cout<<"Van ferfi"<<endl;
    }
    else
    {
        cout<<"Nincs"<<endl;
    }
}
