#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

struct Vasarlas
{
    std::string datum;
    std::string vkod;
    std::vector<std::string> aruk;
};

class Enor
{
    public:
        Enor(std::string fnev);
        ~Enor();
        void First();
        void Next();
        Vasarlas Current() const { return akt; }
        bool End() const { return vege; }
    private:
        std::ifstream x;
        Vasarlas akt;
        bool vege;
};

#endif // ENOR_H
