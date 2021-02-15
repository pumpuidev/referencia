#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<vector>
#include<fstream>

struct Cica
{
    std::string nev;
    std::string szin;
    int kor;
    std::vector<std::string> kolykok;
};

class Enor	//ez kb. univerzalis minden feladatra. csak a Next ami kulonbozik (vagy a beolvaso operator)
{
    public:
        Enor(std::string fnev);
        ~Enor();
        void First() {  vege = false; Next(); }
        void Next();
        Cica Current() const { return akt; }
        bool End() const { return vege; }
    private:
        std::ifstream x;
        bool vege;
        Cica akt;
};

#endif // ENOR_H
