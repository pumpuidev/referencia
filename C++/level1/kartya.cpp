#include <iostream>

using namespace std;

int main()
{
    string lap;
    int i,lapertek;
    const string clapok[8]={"VII","VIII","IX","X","ALSO","FELSO","KIRALY","ASZ"};
    const int certek[8]={7,8,9,10,2,3,4,11};
    cout<<"lapot: ";
    cin>>lap;
    i=0;
    while((i<=7)&&(clapok[i]!=lap))
    {
        i++;
    }
    if(i>=8)
    {
        cout<<"hiba";
        exit(1);
    }
    lapertek=certek[i];
    cout<<"a lap erteke: "<<lapertek;
}
