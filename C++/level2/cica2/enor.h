#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<vector>
#include<fstream>

struct Cica		//ez most egyedi felsorolo, csak azt soroljuk fel, ami erdekel minket
{
    std::string nev;
    std::string szin;
    int kolykokSzama;
};

class Enor	//ez a resze tovabbra is univerzalis
{
    public:
        Enor(std::string fnev);
        ~Enor();
        void First() { vege = false; Next(); }
        void Next();
        Cica Current() const { return akt; }
        bool End() const { return vege; }
    private:
        std::ifstream x;
        bool vege;
        Cica akt;
};

#endif // ENOR_H
