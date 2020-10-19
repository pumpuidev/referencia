#include <iostream>
#include <string.h>
using namespace std;

bool Helyes(string s){
    if (s.length() >= 1 && s[0]=='1' || s[0]=='2'){
        return true;
    }else{
        return false;
    }
}

int main()
{
    int dolgozokszama;
    bool hiba;
    string tmp;
    do{
        cout << "A dolgozok szama:" << endl;
        cin >> dolgozokszama;
        hiba = cin.fail();
        if(hiba){
            cout << "Hibas beolvasas" << endl;
            cin.clear(); getline(cin, tmp, '\n'); // cin bemenet cin.clear mindent töröl a bemenetbõl , getline 3 paraméteres az elsõböl a 2. ba teszi addig amíg a 3. strongbe nem jön
        }//
    }while(hiba || dolgozokszama<=0);
    string sziszamok[dolgozokszama];
    for (int i=0; i<dolgozokszama; i++){
        do{
            cout << i+1 << ". dolgozo sziszama: ";
            cin >> sziszamok[i];
            hiba = cin.fail();
            if(hiba){
                cout << "Hibas beolvasas" << endl;
                cin.clear(); getline(cin, tmp, '\n');
            }
        }while(hiba || !Helyes(sziszamok[i]) );
    }
    int i=0;
    while (i < dolgozokszama && !(sziszamok[i][0]=='1')){
        i++;
    }
    bool eredmeny = (i < dolgozokszama);
    if (eredmeny){
        cout << "Volt ferfi" << endl;
    }else{
        cout << "Nem volt ferfi" << endl;
    }
    return 0;
}
