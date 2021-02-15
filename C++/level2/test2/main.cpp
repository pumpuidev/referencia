#include <iostream>
#include "seqinfile.h"

using namespace std;

int main()
{
    SeqInFile t("input.txt");
    for(t.First(); !t.End(); t.Next() ){
        Student e = t.Current();
        cout << e.name;
        if(e.accept && e.exam>0){
            cout << "Hiba1" << endl;
        }else if(e.include && e.exam>30){
            cout << "Hiba1" << endl;
        }else{
            int point = 0;
            int test = e.test1+e.test2;
            if(e.accept && test>=40){
                point = test;
            }else if((!e.accept || test<40) && e.include){
                point = test/2 + e.exam;
            }else if((!e.accept || test<40) && !e.include){
                point = e.exam;
            }
            cout << point/10 << endl;
        }
    }
    return 0;
}
