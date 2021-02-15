#ifndef ENOR_H
#define ENOR_H

#include <iostream>
#include <fstream>

struct Film
{
    std::string nev;
    std::string terem;
    std::string ido;
    int g;
    int d;
    int f;
};

class Enor
{
    public:
        Enor(std::string fnev);
        ~Enor();
        void First();
        bool End() const;
        Film Current() const;
        void Next();

    private:
        std::ifstream x;
        bool vege;
        Film dx;

        bool ido(std::string s);
};

#endif // ENOR_H
