#include <iostream>

using namespace std;

int main()
{
    int ar=0;
    float learazas=0, osszeg;
    while(ar<=0)
    {
        cout << "Kerem irja be az eredeti arat" << endl;
        cin >> ar;
    }
    while (learazas <=0 || learazas >= 100){
        cout << "Kerem adja meg a learazas szazalekat:" << endl;
        cin >> learazas;
    }
    if(learazas>50)

    {
        cout << "Az arut erdemes megvenni," << endl;
        cout << "a termek ara:" << ar-(ar*(learazas/100))<< endl;
    }
    else
    {
        cout << "Az arzt nem erdemes megvenni,"<< endl;
        cout << "A termek ara:" << ar-(ar*(learazas/100))<< endl;
    }


    return 0;
}
