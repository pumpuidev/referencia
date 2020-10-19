#include <iostream>
#include <cstdlib>
/*Prorok Ernest
Filspa
hbv
ernest.prorok@gmail.com */
using namespace std;

int main()
{
    int jegy;
    cin>>jegy;
    if(jegy>20){
        cout<<"nagyobb mint 20";
        exit(1);
    }
    if(jegy<1){
        cout<<"kisebb mint 1";
        exit(2);
    }
    if(jegy<10){
        cout<<"megbukott";
    }
    return 0;
}
