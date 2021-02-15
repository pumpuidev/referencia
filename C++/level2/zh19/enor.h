#ifndef ENOR_H
#define ENOR_H

#include <iostream>
#include <fstream>
#include <vector>

enum Status { Norm, Abnorm };

struct Eredmeny
{
    int szorzo;
    int pont;
};

struct Kutymuty
{
    std::string nev; //ez uj
    std::string chip;
    std::vector<Eredmeny> eredmenyek;
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
        Status sx;
        Kutymuty dx;
        std::ifstream x;
};

#endif // ENOR_H
