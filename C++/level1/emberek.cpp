#include <iostream>

using namespace std;



int main()
{
int n=0;
cin >> n;


int eletkor [n];
int fizetes [n];

for (int i=0; i<n; i++)
{

cin>>eletkor[i];
cin>>fizetes[i];
}

//elso feladat
int max = 0;
for (int i = 0; i < n; i++)
{
    if (eletkor[i] > eletkor[max])
    {
        max = i;
    }

}
cout << max+1 << endl;
// masodik feladat
int darab=0;
for (int i = 0;i < n ; i++)
{
if(eletkor[i]>40 && fizetes[i]>200000)
darab++;
}

cout << darab << endl;


}



