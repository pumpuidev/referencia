
#include <iostream>

using namespace std;

int main()
{
    int n;
    int db=0;
    const int MaxN=100;
    string cimek[MaxN];
    int mennyisegek[MaxN];
    bool rossz;

    do{
        cout << "hany darab tankonyv";
        cin>>n;
        rossz=cin.fail() || !(n>=0) || !(n<100);
        if (rossz){
            cout<<"hiba, probald ujra"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');}
        }
    while (rossz);


    for (int i=0;i<n;++i){
        cout<<"kerem a(z) "<<i+1<<" tankonyv nevet"<<endl;
        cin>>cimek[i];

        do{
        cout<<"kerem a(z) "<<i+1<<" tankonyv mennyiseget"<<endl;
        cin>>mennyisegek[i];
        rossz=cin.fail() || !(mennyisegek[i]>=0) /*|| !(mennyisegek[i]<100)*/;
        if (rossz){
            cout<<"hiba, probald ujra"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');}
        }
    while (rossz);
    }


    for (int i=0; i<n;i++){
        if (mennyisegek[i]>100){
            db=db+1;
            //cout<<"B feladat megoldasa: "<<db;
        }

    }cout<<"B feladat megoldasa: "<<db<<endl;
    /*do {
        cout<<"A feladat megoldasa: "<<cimek[i];
    }
    while (mennyisegek[i]<mennyisegek[i+1]);*/

    for (int i=0;i<n;++i){
        if (mennyisegek[i]<mennyisegek[i+1]){
            cout<<"A feladat megoldasa: "<<cimek[i];
        }
    }

    return 0;
}
