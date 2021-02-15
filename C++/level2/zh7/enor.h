#ifndef ENOR_H
#define ENOR_H

#include <fstream>
#include <iostream>
#include <vector>

struct Sziget
{
    std::string nev;
    std::string kont;
    int sereg;
    std::vector<std::string> csatak;
    std::string birtoklo;
};

class Enor
{
    public:
        Enor(std::string fnev);
        ~Enor();

        void First();
        void Next();
        Sziget Current() const;
        bool End() const;

    private:
        std::ifstream x;
        bool vege;
        Sziget dx;

        bool datum(std::string s);
};

#endif // ENOR_H
