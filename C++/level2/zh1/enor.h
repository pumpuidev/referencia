#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include<string>
#include<fstream>

struct Elem
{
    std::string sor;
};

class Enor
{
public:
    Enor();
    ~Enor();
    void First();
    void Next();
    Elem Current();
    bool End();
private:
    std::ifstream x;
    Elem e;
    bool vege;
};

#endif // ENOR_H_INCLUDED
