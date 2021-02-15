#include "seqinfile.h"
#include <cstdlib>
#include <iostream>

using namespace std;

SeqInFile::SeqInFile(const string &fname)
{
    x.open(fname.c_str());
    if(x.fail()){
        cout << "Fájlnyitási hiba!\n";
        exit(1);
    }
}

void SeqInFile::read()
{
    string word;
    x >> word;
    if ( !x.fail()) {
        st = norm;
        e.name = "";
        while (word!="0" && 0==atoi(word.c_str())){
            e.name += word+" ";
            x >> word;
        }
        e.test1 = atoi(word.c_str());
        x >> e.test2;
        x >> e.exam;
        char ch;
        x >> ch;
        e.accept  = 'I'==ch ? true : false;
        x >> ch;
        e.include = 'I'==ch ? true : false;
    } else st = abnorm;
}


