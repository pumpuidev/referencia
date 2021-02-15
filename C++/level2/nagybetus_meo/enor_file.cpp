#include "enor_file.h"

using namespace std;

Enor_file::Enor_file(std::string filenev)
{
    x.open(filenev.c_str());
    if(x.fail())
    {
        cerr<<"Filemegnyitasi hiba";
        sx = Abnorm;
    }
}

void Enor_file::First()
{
    sx = Norm;
    Next();
}

void Enor_file::Next()
{
    x.get(dx);  //a sima >> atugrana a whitespace-eket
    if(x.fail())
        sx = Abnorm;
}

bool Enor_file::End() const
{
    return Abnorm == sx;
}

char Enor_file::Current() const
{
    return dx;
}
