#include <iostream>
#include <cmath>

using namespace std;

bool Helyes (int N){
    string tmp;
    if (cin.fail()){
        cout<<"hibas \n";
        cin.clear();
        getline(cin,tmp,'\n');
        return false;
    }else {
    if (cin.peek()!='\n'){
        getline(cin,tmp,'\n');
    }
    if (N<3)cout<<"Tul kicsi\n";
    }
    return (N>2);
}
bool HelyesV (int K, int N){
    if (N<K)cout<<"Tul kicsi\n";
    return (N>=K);
}
bool Prim(int n){
    int i=2;
    while ((i<=sqrt(n))&&((n % i) !=0)){
        ++i;
    }return (i>sqrt(n));
}
bool Ikerprim(int n){
    return Prim(n)&&Prim(n+2);
}
int main()
{
    int K,V;
    bool Van;
    int Ind;

    do {
        cout<<"Kezdo: "; cin>>K;
    }while (!Helyes(K));
    do{
        cout<<"Vege: "; cin>>V;
    }while (!HelyesV(K,V));

    int i=K;
    while((i<=V)&&(!Ikerprim(i))){
        ++i;
    }
    Van=(i<=V);
    Ind=i;
    if (Van){
    cout<<"Ikerprim: "<<Ind<<" , "<<Ind+2<<"\n";}
    else {cout<<"Nincs"<<endl;}

    return 0;
}
