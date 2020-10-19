#include <iostream>

using namespace std;

int main()
{

    int n=0;
    cin>>n;
    int tav[n];
    int ar[n];
    for (int i=0;i<n;i++)
        {
            cin>>tav[i];
            cin>>ar[i];
        }
//a feladat
int max = 0;
for (int i = 1; i < n; i++)
    {
        if (tav[i] > tav[max])
        {
            max = i;
        }
    }

//b feladat
int max2=0;
for(int i=0;i<n;i++)
{
    if(tav[i]<1000)
    {


        if (ar[i] > ar[max2])
                {
                    max2 = ar[i];
                }

    }
}
//a
cout << max+1<<endl;
//b
cout<<max2 << endl;
//c
cout << endl;
//d
cout << endl;
}
