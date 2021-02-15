#include <iostream>
#include<cstdlib>

using namespace std; //megnezni a switch case of - t

int main()
{
    int a,k,h;
    cout << "add a hatvanyyalapot!" << endl;
    cin>>a;
    if(cin.fail()){
        cerr<<"nem egesz szam"<<endl;
        exit(1);
    }
    //cout<<a;
    cout << "add a kitevot!" << endl;
    cin>>k;
    if(cin.fail() || k<0){
        cerr<<"nem negativ szam"<<endl;
        exit(2);
    }
    h=1;
    for(int i=1;i<=k;++i){
        h*=a;
    }

    cout<<"tehat a hatvany: "<<h<<endl;


    return 0;
}
