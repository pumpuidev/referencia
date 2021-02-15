#include<iostream>
#include"enor.h"

using namespace std;

int main()
{
    Enor t("pussy.txt");
    //Ellenorzo kiiras:
//    for(t.First();!t.End();t.Next())
//        cout<<t.Current().nev<<" "<<t.Current().kolykokSzama<<" "<<t.Current().szin<<endl;

	//feltmaxker:
    int max;
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
                max = e.kolykokSzama;
                elem = e;
            }
            else
            {
                if(max < e.kolykokSzama)
                {
                    max = e.kolykokSzama;
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
