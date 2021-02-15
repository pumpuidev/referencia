#ifndef ENOR_H
#define ENOR_H

#include <iostream>
#include <fstream>
#include <vector>

struct Utas
{
    std::string azonosito;
    std::string legkorabbi;
    int utazasok;   //uj
};

class Enor
{
    public:
        Enor(std::string fnev);
        ~Enor();
        void First();
        void Next();
        bool End() const;
        Utas Current() const;

    private:
        std::ifstream x;
        bool vege;
        Utas dx;
};

#endif // ENOR_H
