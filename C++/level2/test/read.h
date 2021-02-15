
//Feladat:   segédfüggvény egésszámok billentyûzetrõl való beolvasásához

#ifndef _READ_
#define _READ_

#include <string>

bool all(int k);
bool nat(int k);
bool neg(int k);

int read_int(const std::string &msg, const std::string &err, bool valid(int) = all);

#endif
