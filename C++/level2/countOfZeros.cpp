#include <iostream>
#include <vector>
#include "console_utilities.h"

using namespace std;

size_t getCountOfZeros(const vector<int> &v);

int main()
{
    vector<int> v = readVector();
    size_t countOfZeros = getCountOfZeros(v);
    cout<<countOfZeros<<endl;

    return 0;
}

size_t getCountOfZeros(const vector<int> &v)
{
    //szamlalas
    size_t c = 0;

    for(size_t i = 2;i<v.size();++i)
    {
        if(v[i] == 0 && v[i-1] > 0 && v[i-2] > 0)
        {
            ++c;
        }
    }

    return c;
}
