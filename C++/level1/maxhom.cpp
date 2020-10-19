#include <iostream>

using namespace std;

int main()
{


int N=0;
int maxhom[N];
int minhom[N];
int fagyosnap = 0;
int maxkul = 0;


cin>>N;
for (int i=0; i<N; i++)
    {
  cin>>minhom[i];
  cin>>maxhom[i];
    }
//1. feladat
for (int i=0;i<N; i++)
    {
        if((minhom[i]<=0) || (maxhom[i]<=0))
        {
            fagyosnap++;
        }

    }
//2. feladat
for (int i=1;i<N;i++)
    {
        if((maxhom[i]-minhom[i])>(maxhom[maxkul]-minhom[maxkul])){maxkul=i;}
    }

//3. feladat egy napot, amikor a napi maximum kisebb az elõzõ napi minimumnál ,( -1-et, ha nincs ilyen nap);
/*int jo=0
for (int i=2; i<N && jo=1;i++)
    {

    if(maxhom[i]< minhom[i-1])
        {
            cout << maxhom[i] <<endl;

        }
        else{ cout <<"-1"<<endl;}
        }
*/
    cout << fagyosnap << endl;
    cout << maxkul+1
 << endl;
}
