#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>

struct Adat
{
    std::string nev;
    bool vankonk;
    bool mind10alatt;

    friend std::ostream& operator<<(std::ostream &os, const Adat &a);
    friend std::istream& operator>>(std::istream &is, Adat &a);
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
