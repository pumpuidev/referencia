#include "enor.h"
#include<cstdlib>
#include<iostream>

using namespace std;

Enor::Enor()
{
    x.open("f.txt");
    if(x.fail())
    {
        cout<<"fajlmegnysitasi hiba"<<endl;
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
}

void Enor::Next()
{
    getline(x,e.sor);
    vege = x.fail();
}

bool Enor::End()
{
    return vege;
}

Elem Enor::Current()
{
    return e;
}
