#include "enor.h"
#include<cstdlib>
#include<iostream>

using namespace std;

Enor::Enor()
{
    x.open("f.txt");
    if(x.fail())
    {
        cout<<"Fajlmegnyitasi hiba."<<endl;
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::First()
{
    Next();
    if(vege)
    {
        cout<<"Ures."<<endl;
        exit(2);
    }
}

void Enor::Next()
{
    getline(x,e.sor);
    vege = x.fail() || e.sor =="" ;
}

bool Enor::End()
{
    return vege;
}

Elem Enor::Current()
{
    return e;
}
