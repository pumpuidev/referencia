#include<iostream>
#include "console_utilities.h"

using namespace std;

int sumOfPrimes(int m, int n);
bool isPrime(int p);

int main()
{
    cout<<"Gimme interval"<<endl;
    int m = readNumber();
    int n = readNumber();
    cout<<"Sum of primes between "<<m<<" and "<<n<<": ";
    cout<<sumOfPrimes(m,n)<<endl;
    return 0;
}

int sumOfPrimes(int m, int n)
{
    //osszegzes
    int s = 0;
    for(int i=m; i<=n; ++i)
        if(isPrime(i))
            s += i;
    return s;
}

bool isPrime(int p)
{
    //szamlalas
    unsigned divisors = 0;
    for(int i = 1; i<=p; ++i)
        if(p % i == 0)
            ++divisors;

    //osszetett fv.
    return divisors == 2;
}
