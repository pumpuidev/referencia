#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    char fnev[20]="adat.be";
    ifstream input(fnev,ios::in);
    int n,x,y;
    input>>n;
    for(int i=0;i<n;++i){
        input>>x>>y;
        cout<<x<<" : "<<y<<endl;
    }
    input.close();
    return 0;
}
