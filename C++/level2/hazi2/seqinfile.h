#ifndef SEQINFILE_H
#define SEQINFILE_H

#include <fstream>

struct Student{
    std::string name;
    int test1, test2, exam;
    bool accept, include;
};

enum Status{abnorm, norm};

class SeqInFile
{
    public:
        SeqInFile(const std::string &fname);
        void first() { read();}
        void next()  { read();}
        Student current() const { return e; }
        bool end() const { return abnorm==st; }
    private:
        std::ifstream x;
        Student e;
        Status st;

        void read();
};

#endif // SEQINFILE_H
