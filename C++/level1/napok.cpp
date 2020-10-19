#include <iostream>

using namespace std;

const string HetNapjai[]={"hetfo","kedd","szerda","csutortok","pentek","szombat","vasarnap"};

bool Helyes(int hossz){
    if (hossz<=0) cout<<"Csak pozitiv egesz szamot kerek\n";
    return hossz>0;
}

bool HelyesNap(string kezd){
    int i=1;
    while ((i<=7) && (kezd!=HetNapjai[i-1])){
        i++;
    }
    return i<=7;
}

int main()
{
    string kezd,vege;
    int kezdi,vegei,hossz;

    do{
        cout<<"A tabor hossza?"; cin>>hossz;
    }while(!Helyes(hossz));

    do {
        cout<<"Melyik napon kezdodik? (hetfo,kedd,...)";cin>>kezd;
    }while(!HelyesNap(kezd));

    kezdi=1;
    while (kezd!=HetNapjai[kezdi-1]){
        kezdi++;
    }
    //cout<<kezdi;
    vegei=((kezdi+hossz-1)%7);
    //cout<<vegei;
    vege=HetNapjai[vegei-1];

    cout<<vege<<"\n";


    return 0;
}
