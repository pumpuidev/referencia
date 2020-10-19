#include <iostream>

using namespace std;

void beolvasas(int&n);
void primfelbontas(int n,int ptf[],int&db);
void kiiras(const int n,const int ptf[],const int db);

int main()
{
    int n;
    int db;
    int ptf[100];
    beolvasas(n);
    primfelbontas(n,ptf,db);
    kiiras(n,ptf,db);
}

void beolvasas(int&n)
{
    do
    {
        cout<<"Melyik: ";
        cin>>n;
    }while(!(n>1));
}

void primfelbontas(int n,int ptf[],int&db)
{
    db=0;
    int i=2;
    while(i<=n)
    {
        if((n%i)==0)
        {
            ptf[db]=i;
            n=n/i;
            db++;
        }
        else
        {
            i++;
        }
    }
}

void kiiras(const int n,const int ptf[],const int db)
{
    cout<<n<<" primtenyezos felbontasa: ";
    for(int i=0;i<db;i++)
    {
        cout<<ptf[i]<<", ";
    }
}

