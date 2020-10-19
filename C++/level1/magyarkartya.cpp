#include <iostream>

using namespace std;

int main()
{
    string k;
    int e;
    const string kartyak[8] = {"vii","viii","ix","x","also","felso","kiraly","asz"};
    const int ertekek[8]= {7,8,9,10,2,3,4,11};
    bool rossz;
    do
    {
    cout << "Kartya: ";
    cin >> k;
    int i=0;
    while(i<=7 && kartyak[i]!=k)
        {
        i=i+1;
        }
        rossz = i>7 ;
        if (rossz)
        {
        cout << "rossz kartya" << endl;
        }
    }
    while (rossz);


    int i=1-1;
    while(kartyak[i] != k)
    {
        i= i+1;
    }
    e=ertekek[i];
    cout << "Ertek: " << e << endl;
    return 0;
}
