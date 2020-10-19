
//Feladat: Magyar névhez tartozó monogram
#include <iostream>

using namespace std;
bool Nagybetu_e(char betu);
bool Dupla_e(string ketbetu);

int main()
{   string Nev,Mon,K;
    cout<<"Magyar nevbol monogramot keszit"<<endl<<endl;
    cout<<"Kerem a nevet: ";
    getline(cin,Nev);               //mivel a névben space-k is vannak, ezért nem olvasható be igy: cin>>Nev

    Mon="";
    for(int i=0;i<Nev.length()-1;++i){
        K=Nev[i];
        K=K+Nev[i+1];               //karakter és string tipus

        if (Dupla_e(K)){
            Mon=Mon+K;
        }
        else {                      // else if -ként is leirhato lett volna
            if (Nagybetu_e(Nev[i])){
                Mon=Mon+Nev[i];
            }
        }
    }

    cout<<"A nevhez tartozo monogram: "<<Mon<<endl;
    return 0;
}

bool Nagybetu_e(char betu){ //megállapítja a betûrõl, hogy nagybetû volt-e
    const char Nagybetuk[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Z','X','Y'};
    int i=0;
    while((Nagybetuk[i]!=betu)&&(i<26)){
        i++;
    }
    return i<26;
}

bool Dupla_e(string ketbetu){ //megállapítja két betürõl, hogy dupla nagybetû volt-e
    const string Dupla[8]={"Cs","Dz","Gy","Ly","Ny","Sz","Ty","Zs"};
    int i=0;
    while ((i<8)&&(Dupla[i]!=ketbetu)){
        i++;
    }
    return (i<8);
}
