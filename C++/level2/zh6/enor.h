#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include<string>
#include<fstream>
#include<vector>

enum Status { abnorm, norm };

struct Elem
{
    std::string nev;
    double atlagosIdo;
    bool novekvo;
};

class Enor
{
public:
    Enor(std::string nev);
    ~Enor();
    void First();
    void Next();
    Elem Current();
    bool End();
private:
    std::ifstream x;
    Elem dt;
    Status st;
};

#endif // ENOR_H_INCLUDED
