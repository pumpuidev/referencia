
//Feladat:   seg�df�ggv�ny eg�ssz�mok billenty�zetr�l val� beolvas�s�hoz

#ifndef _READ_
#define _READ_

#include <string>

bool all(int k);
bool nat(int k);
bool neg(int k);

int read_int(const std::string &msg, const std::string &err, bool valid(int) = all);

#endif
