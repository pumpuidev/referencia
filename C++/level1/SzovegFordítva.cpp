
//Feladat:
#include <iostream>

using namespace std;

int main()
{   string S,T;
    cout<<"Szoveg kiirasa forditva"<<endl<<endl;
    cout<<"Kerem a szoveget";
    cin>>S;     //nincs el�felt�tel, nem ellen�rz�nk semmit

    T="";       //T tartalma kezdetben az �res sz�veg
    for(int i=S.length()-1;i>=0;--i){
        T=T+S[i];
    }

    cout << "A szoveg forditva:" << T<<endl;
    return 0;
}
