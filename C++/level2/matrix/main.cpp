//Feladat:       Kiválasztás egy végtelen "mátrix" bejárásával

#include <iostream>
#include "read.h"

using namespace std;

double f(int i) { return i;}
double g(int j) { return j;}

// Típusérték:      egész számpárok sorozata
// Reprezentáció:   egész számpárok (i,j) és az összegük (k)
// Mûveletek:       first(), next(), current()  - felsoroló mûveletek
class Enor{
public:
    struct Pair{ int i; int j;};

    void first(){ k = cur.i = cur.j = 0; }
    void next() { if (cur.j<k) {--cur.i; ++cur.j;} else {++k; cur.i=k; cur.j=0;} }
    Pair current() const { return cur;}
private:
    int k;
    Pair cur;
};

//Feladat: 	        Adottak az f,g : N -> R függvények és az e valós szám.
//                  Tudjuk, hogy van olyen i,j egész, amelyre f(i)+g(j)==e.
//                  Keressünk ilyen i,j egészt!
//Bemenõ adatok:    double e - keresett érték
//Kimenõ adatok:    int i, j - azon indexek, ahol f(i)+g(j)==e
//Tevékenység:	    Beolvassa a keresett valós számot,
//                  kétféleképpen felsorolja a lehetséges i, j index párokat,
//		            vizsgálja az f(i)+g(j)==e összefüggést, és az elsõ egyezésnél megáll.
int main()
{
    double e = read_real("Keresett ertek: ", "Valos szamot varok!");

// első változat

    Enor t;
    for( t.first() ; f(t.current().i)+g(t.current().j)!=e; t.next() );

    cout << "A keresett elem az f(" << t.current().i << ")+g(" << t.current().j << ") osszeggel azonos\n";

// második változat

    int i, j, k;
    for(i = j = k = 0; f(i)+g(j)!=e; ){
        if(j < k) { --i; ++j;} else { ++k; i = k; j = 0;}
    }

    cout << "A keresett elem az f(" << i << ")+g(" << j << ") osszeggel azonos\n";

    return 0;
}

