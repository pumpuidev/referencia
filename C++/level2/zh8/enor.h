#ifndef ENOR_H
#define ENOR_H

#include <fstream>
#include <iostream>
#include <vector>

struct Allat
{
    std::string nev;
    std::string faj;
    int magassag;
    int oltasok;
    bool volt2014oltas; //uj adattag
    bool orokbefogadott;
};

class Enor
{
    public:
        Enor(std::string fnev);
        ~Enor();

        void First();
        void Next();
        Allat Current() const;
        bool End() const;

    private:
        std::ifstream x;
        bool vege;
        Allat dx;
};

#endif // ENOR_H
