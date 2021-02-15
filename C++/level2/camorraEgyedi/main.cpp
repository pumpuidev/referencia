#include<iostream>
#include"enor.h"

using namespace std;

int main()
{
    Enor t("be.txt");
    //Enor t("be2.txt");

    /*for(t.First();!t.End();t.Next())
    {
        cout<<t.Current().nev<<" ";
        cout<<t.Current().mind10alatt<<" ";
        cout<<t.Current().vankonk<<" "<<endl;
    }*/

    bool l = false;
    Adat elem;
    for(t.First();!l && !t.End();t.Next())
    {
        elem = t.Current();
        l = !elem.vankonk && elem.mind10alatt;
    }

    if(l)
        cout<<"Van: "<<elem.nev<<endl;
    else
        cout<<"Nincs."<<endl;

    return 0;
}
