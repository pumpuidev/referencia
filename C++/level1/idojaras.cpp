#include <iostream>

using namespace std;

int main()
{
    int nap;
    int kezd;
    int veg;
    int X;
   cout << "hany napig merted az idojarast?: " << endl;
    cin >> nap;
cin >> X;
    int napok [nap];
    for (int i=0;i<nap;i++)
       {
        cout << "add meg az "<< i+1 << ". nap homersekletet"<< endl;
        cin >> napok [i];
       }
       for (int j=0; j<nap;j++)
       {
           cout << napok [j]<< endl;
       }
       int i=1;
       do
       {
           if(napok[i-1]<X && napok[i]>X)
           {
               kezd=i;
           }
           i++;
       }while(i<nap);
              int j=nap-1;
       do
       {
           if(napok[i+1]<X && napok[i]>X)
           {
               veg=i;
           }
j--;
       }while(i<nap);
       cout << kezd << " es " << veg ;
    return 0;
}
