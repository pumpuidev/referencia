#ifndef ENOR_H
#define ENOR_H

#include <iostream>
#include <fstream>
#include <vector>

enum Status
{
    Norm, Abnorm
};

struct Utazas
{
    std::string idokod;
    std::string jaratszam;
};

struct Utas
{
    std::string nev;    //uj
    std::string azonosito;
    std::vector<Utazas> utazasok;
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
        Status sx;
        Utas dx;
};

#endif // ENOR_H
