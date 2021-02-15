#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("be.txt");
    if(t.End())
    {
        cerr<<"A fajl beolvasasa sikertelen."<<endl;
    }
    else
    {
        //linker
        bool l = false;
        for(t.First();!l && !t.End();t.Next())
        {
            Film f = t.Current();
//            cout<<"\""<<f.nev<<"\" "<<f.terem<<" "<<f.ido<<" "<<f.g<<" "<<f.d<<" "<<f.f<<endl;

            //osszegzes
            int bevetel = f.g * 500 + f.d * 800 + f.f * 1000;
            cout<<f.ido<<" "<<f.terem<<" "<<bevetel<<endl;

            //linker
            l = bevetel > 0 && 0 == f.g && 0 == f.f;
        }

        //linkerrel elkezdett felsorolo befejezese (Firstot elhagyjuk ilyenkor)
        for(;!t.End();t.Next())
        {
            Film f = t.Current();
//            cout<<"\""<<f.nev<<"\" "<<f.terem<<" "<<f.ido<<" "<<f.g<<" "<<f.d<<" "<<f.f<<endl;

            //osszegzes
            int bevetel = f.g * 500 + f.d * 800 + f.f * 1000;
            cout<<f.ido<<" "<<f.terem<<" "<<bevetel<<endl;
        }

        if(l)
            cout<<"Volt csak diakok altal megtekintett film"<<endl;
        else
            cout<<"Nem volt csak diakok altal megtekintett film"<<endl;

    }
    return 0;
}
