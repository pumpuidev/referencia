#include <iostream>
#include "seqinfile.h"

using namespace std;

int process(const Student &e);

int main()
{
    SeqInFile t("input.txt");
    for(t.first(); !t.end(); t.next() ){
        int r = process(t.current());
        if(r==-1) cout << "Elfogadott jegy eseten a vizsgapontszám legyen 0!\n";
        else if(r==-2) cout << "Zarthelyi beszámitaskor a vizsgapontszám ne legyen 30-nál több\n";
        else    cout << r << endl;;
    }
    return 0;
}

int process(const Student &e)
{
    int test = e.test1+e.test2;
    if(e.accept && (test<40 || e.exam>0)) return -1;
    else if(e.include && e.exam>30) return -2;
    else{
        int point = 0;

        if(e.accept && test>=40){
            point = test;
        }else if((!e.accept || test<40) && e.include){
            point = test/2 + e.exam/2;
        }else if((!e.accept || test<40) && !e.include){
            point = e.exam;
        }
        return point/10;
    }
}
