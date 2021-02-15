#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include<string>
#include<fstream>
#include<vector>

enum Status { abnorm, norm };

struct koridoAdat
{
    int sorszam;
    std::string ido;
};

struct Elem
{
    std::string nev;                    //pl.: ALO
    std::string csapat;                 //pl.: Ferrari
    std::vector<koridoAdat> koridok;    //pl.: [(4,"01:22:234"),(5,"01:21:891"),(6,"01:21:234")]
};

class Enor
{
public:
    Enor();
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
