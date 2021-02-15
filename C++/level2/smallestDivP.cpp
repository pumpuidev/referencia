#include<iostream>
#include<vector>
#include "console_utilities.h"

using namespace std;

bool getSmallest(const vector<int> &v, int p, int& min);

int main()
{
    vector<int> v = readVector();
    int p = readNumber();

    cout<<"v: ";
    for(size_t i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"p: "<<p<<endl;

    int min;
    bool l = getSmallest(v, p, min);

    if(l)
        cout<<"The smallest value is: "<<min<<endl;
    else
        cout<<"No value that is oszthato with p"<<endl;

    return 0;
}

bool getSmallest(const vector<int> &v, int p, int& min)
{
    //feltmaxker (ind elhagyva)
    bool l = false;
    for(size_t i = 0; i<v.size(); ++i)
    {
        if(v[i] % p == 0)
        {
            if(l)
            {
                if(min > v[i])
                    min = v[i];
            }
            else
            {
                l = true;
                min = v[i];
            }
        }
    }
    return l;
}
