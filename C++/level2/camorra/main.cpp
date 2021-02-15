#include<iostream>
#include<vector>
#include"enor.h"

using namespace std;

bool osszes10alatt(const vector<int>& v);

int main()
{
    Enor t("be.txt");
    //Enor t("be2.txt");

    /*for(t.First();!t.End();t.Next())
    {
        cout<<t.Current().nev<<" ";
        for(size_t i=0;i<t.Current().penz.size();++i)
            cout<<t.Current().penz[i]<<" ";
        cout<<t.Current().konk<<endl;
    }*/

    bool l = false;
    Adat elem;
    for(t.First();!l && !t.End();t.Next())
    {
        elem = t.Current();
        l = elem.konk == "nincs" && osszes10alatt(elem.penz);
    }

    if(l)
        cout<<"Van: "<<elem.nev<<endl;
    else
        cout<<"Nincs."<<endl;

    return 0;
}

bool osszes10alatt(const vector<int>& v)
{
    bool l = true;

    for(size_t i=0;i<v.size() && l; ++i)
        l = v[i] < 10;

    return l;
}
