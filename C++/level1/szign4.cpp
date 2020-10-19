#include <iostream>

using namespace std;

int main()
{
    float szam;
    int szign;
    cout<<"be szam:";
    cin>>szam;

    if(szam<=0){if(szam<0)szign=-1;else szign=0;
    }else szign=1;
    cout<<szign<<endl;
    return 0;
}
