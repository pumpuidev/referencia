
//Feladat: Névbõl monogram készítés
#include <iostream>

using namespace std;
bool Nagybetu_e(char betu);
int main()
{   string Nev,Mon;
    cout<<"Nevbol monogramot keszit"<<endl<<endl;
    cout<<"Kerem a nevet: ";
    getline(cin,Nev);               //mivel a névben space-k is vannak, ezért nem olvasható be igy: cin>>Nev

    Mon="";
    for(int i=0;i<Nev.length();++i){
        if (Nagybetu_e(Nev[i])){
            Mon=Mon+Nev[i];
        }
    }

    cout<<"A nevhez tartozo monogram: "<<Mon<<endl;
    return 0;
}

bool Nagybetu_e(char betu){ //megállapítja abetûrõl, hogy nagybetû volt-e
    const char Nagybetuk[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Z','X','Y'};
    int i=0;
    while((Nagybetuk[i]!=betu)&&(i<26)){
        i++;
    }
    return i<26;
}
