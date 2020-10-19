#include <iostream>

using namespace std;

int nagyobb(int a,int b)
{
    if(a<b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void csere(int&a,int&b)
{
    int cs=a;
    a=b;
    b=cs;
}

int main()
{
    int a=2;
    int b=3;
    cout<<nagyobb(a,b)<<endl;
    csere(a,b);
    cout<<a<<", "<<b;
}
