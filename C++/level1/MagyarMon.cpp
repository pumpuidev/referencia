
//Feladat: Magyar n�vhez tartoz� monogram
#include <iostream>

using namespace std;
bool Nagybetu_e(char betu);
bool Dupla_e(string ketbetu);

int main()
{   string Nev,Mon,K;
    cout<<"Magyar nevbol monogramot keszit"<<endl<<endl;
    cout<<"Kerem a nevet: ";
    getline(cin,Nev);               //mivel a n�vben space-k is vannak, ez�rt nem olvashat� be igy: cin>>Nev

    Mon="";
    for(int i=0;i<Nev.length()-1;++i){
        K=Nev[i];
        K=K+Nev[i+1];               //karakter �s string tipus

        if (Dupla_e(K)){
            Mon=Mon+K;
        }
        else {                      // else if -k�nt is leirhato lett volna
            if (Nagybetu_e(Nev[i])){
                Mon=Mon+Nev[i];
            }
        }
    }

    cout<<"A nevhez tartozo monogram: "<<Mon<<endl;
    return 0;
}

bool Nagybetu_e(char betu){ //meg�llap�tja a bet�r�l, hogy nagybet� volt-e
    const char Nagybetuk[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Z','X','Y'};
    int i=0;
    while((Nagybetuk[i]!=betu)&&(i<26)){
        i++;
    }
    return i<26;
}

bool Dupla_e(string ketbetu){ //meg�llap�tja k�t bet�r�l, hogy dupla nagybet� volt-e
    const string Dupla[8]={"Cs","Dz","Gy","Ly","Ny","Sz","Ty","Zs"};
    int i=0;
    while ((i<8)&&(Dupla[i]!=ketbetu)){
        i++;
    }
    return (i<8);
}
