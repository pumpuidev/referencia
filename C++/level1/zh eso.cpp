#include <iostream>

using namespace std;

int main()
{
    //beolvasás
    int n;
    cin>>n;
    int eso[n+1][7];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=7; j++)
        {
            cin>>eso[i][j];
        }
    }
    //a) feladat
    int sum[n+1];
    for(int i=1; i<=n; i++)
    {
        sum[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=7; j++)
        {
            sum[i]+=eso[i][j];
        }
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    //b) feladat
    int maxind=1;
    for(int i=2; i<=n; i++)
    {
        if(sum[i]>sum[maxind])
        {
            maxind=i;
        }
    }
    cout<<maxind;
    cout<<endl;
    //c) feladat
    int no[1001];
    int db=0;
    bool novekszik;
    for(int i=1; i<=n; i++)
    {
        novekszik=true;
        for(int j=2; j<=7; j++)
        {
            if(eso[i][j]<=eso[i][j-1])
            {
                novekszik=false;
            }
        }
        if(novekszik)
        {
            db++;
            no[db]=i;
        }
    }
    cout<<db<<" ";
    for(int i=1; i<=db; i++)
    {
        cout<<no[i]<<" ";
    }
    cout<<endl;
    //d) feladat
    int d=n/2;
    int NemEsett_db[d+2];           //d+1 darab intervallum lesz, hiszen pl. 10 hét esetén az elsõ héttõl, és a hatodik héttõl is
    for(int i=1; i<=d+2; i++)       //tudunk számolni 5 hetet
    {
        NemEsett_db[i]=0;
    }
    for(int i=1; i<=d+1; i++)
    {
        for(int j=0; j<=d-1; j++)
        {
            for(int nap=1; nap<=7; nap++)
            {
                if(eso[i+j][nap]==0)
                {
                    NemEsett_db[i]++;
                }
            }
        }
    }
    maxind=1;
    for(int i=1; i<=d+1; i++)
    {
        if(NemEsett_db[i]>NemEsett_db[maxind])
        {
            maxind=i;
        }
    }
    cout<<maxind;
    cout<<endl;
    //e) feladat
    struct intervallum
    {
        int kezdet;
        int hossz;
    }szakasz[n+1];

    for(int i=1; i<=n; i++)
    {
        szakasz[i].hossz=0;
    }
    db=0;
    bool szakaszban=false;      //azt jelzi, hogy a ciklus éppen egy megfelelõ szakaszt vizsgál-e
    for(int i=1; i<=n; i++)
    {
        if(szakaszban)
        {
            if(sum[i]<=10)
            {
                szakasz[db].hossz++;
            }else
            {
                szakaszban=false;
            }
        }else
        {
            if(sum[i]<=10)
            {
                szakaszban=true;
                db++;
                szakasz[db].hossz++;
                szakasz[db].kezdet=i;
            }
        }
    }
    if(db==0)
    {
        cout<<db;
    }else
    {
        maxind=1;
        for(int i=1; i<=db; i++)
        {
            if(szakasz[i].hossz>szakasz[maxind].hossz)
            {
                maxind=i;
            }
        }
        cout<<szakasz[maxind].kezdet<<" "<<szakasz[maxind].kezdet+szakasz[maxind].hossz-1;
    }
    cout<<endl;
    return 0;
}
