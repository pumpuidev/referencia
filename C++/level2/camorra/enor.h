#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

struct Adat
{
    std::string nev;
    std::vector<int> penz;
    std::string konk;
};

class Enor
{
    public:
        Enor(std::string nev);
        virtual ~Enor();
        void First() { vege = false; Next(); }
        void Next();
        bool End() const { return vege; }
        Adat Current() const { return akt; }
    private:
        Adat akt;
        bool vege;
        std::ifstream x;
};

#endif // ENOR_H
