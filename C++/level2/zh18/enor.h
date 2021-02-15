#ifndef ENOR_H
#define ENOR_H

#include <iostream>
#include <fstream>
#include <vector>

struct Kutymuty
{
    std::string nev;
    std::string chip;
    bool sikeres;
    int osszpont;
};

class Enor
{
    public:
        Enor(std::string fnev);
        ~Enor();
        void First();
        void Next();
        Kutymuty Current() const;
        bool End() const;

    private:
        bool vege;
        Kutymuty dx;
        std::ifstream x;
};

#endif // ENOR_H
