
//Feladat: N�vb�l monogram k�sz�t�s
#include <iostream>

using namespace std;
bool Nagybetu_e(char betu);
int main()
{   string Nev,Mon;
    cout<<"Nevbol monogramot keszit"<<endl<<endl;
    cout<<"Kerem a nevet: ";
    getline(cin,Nev);               //mivel a n�vben space-k is vannak, ez�rt nem olvashat� be igy: cin>>Nev

    Mon="";
    for(int i=0;i<Nev.length();++i){
        if (Nagybetu_e(Nev[i])){
            Mon=Mon+Nev[i];
        }
    }

    cout<<"A nevhez tartozo monogram: "<<Mon<<endl;
    return 0;
}

bool Nagybetu_e(char betu){ //meg�llap�tja abet�r�l, hogy nagybet� volt-e
    const char Nagybetuk[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Z','X','Y'};
    int i=0;
    while((Nagybetuk[i]!=betu)&&(i<26)){
        i++;
    }
    return i<26;
}
