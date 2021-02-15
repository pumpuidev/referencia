#include<iostream>
#include"enor.h"

using namespace std;

int main()
{
    Enor t("pussy.txt");
    //Ellenorzo kiiras:
    /*for(t.First();!t.End();t.Next())
    {
        cout<<t.Current().nev<<" "<<t.Current().kor<<" ";
        for(size_t i=0;i<t.Current().kolykok.size();++i)
            cout<<t.Current().kolykok[i]<<" ";
        cout<<t.Current().szin<<endl;
    }*/

	//feltmaxker:
    size_t max;
    Cica elem;
    bool l = false;
    for(t.First();!t.End();t.Next())
    {
        Cica e = t.Current();
        if(e.szin == "cirmos")
        {
            if(!l)
            {
                l = true;
                max = e.kolykok.size();
                elem = e;
            }
            else
            {
                if(max < e.kolykok.size())
                {
                    max = e.kolykok.size();
                    elem = e;
                }
            }
        }
    }

    if(!l)
        cout<<"Sajnos nem rendelkezunk cirmos cicaval. Pedig hova lett a vaj?"<<endl;
    else
        cout<<"A legszaporabb cirmos cica a "<<elem.nev<<" nevre nem hallgat legjobban."<<endl;

    return 0;
}
