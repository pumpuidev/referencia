
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    int N;
    string fajlnev;                   //f�jlb�l olvasunk be
    ifstream f;                       //f�jlv�ltoz� defini�l�sa
    struct TVili{                     //Adatszerkezet defini�l�sa
        int sor;
        int tav;
        int erk;
        int ind;
    };
    //Beolvas�s
    do {
        cout << "fajlnev (kiterjesztessel egyutt): ";
        cin >> fajlnev;
        f.open (fajlnev.c_str());
        if (f.fail()) {
            cout << "hiba a fajl megnyitasa kozben!"<<endl;
        }
    } while (f.fail());
    //Beolvas�s v�ge
    f >> N;
    TVili Vili[N];                    //Adatszerkezet deklar�l�sa

    char c;                           //�llom�s sorsz�ma miatti pont bolvas�s�ra
    for (int i=0;i<N;i++) {
        f >> Vili[i].sor;
        f >> c;
        f >> Vili[i].tav;
        f >> Vili[i].erk;
        if (i==N-1) {
                Vili[i].ind=0;
        } else {f >> Vili[i].ind;};
    }
    f.close();

    //C r�szfeladat
    cout << "C: Az utvonal hossza: ";
    int hossz=0;
    for (int i=0;i<N;i++) {
        hossz +=Vili[i].tav;
    }
    cout <<hossz<<endl;

    //UU r�szfeladat
    cout << "UU: 1000 meternel hosszabb allomasszakaszok: "<<endl;
    int db=0;
    if (N!=1) {
        for (int i=0;i<N;i++) {
            if (Vili[i].tav >= 1000) {
                cout << "Az "<<Vili[i-1].sor<<". es "<<Vili[i].sor<<". allomas kozott"<<endl;
                db++;
            }
        }
    }
    if (db==0) {
    cout << "Nincs ilyen szakasz"<<endl;
    }

    //CCC r�szfeladat
    cout << "CCC: Legkozelebbi megallo: "<<endl;
    int j=0;
    if (N!=1) {
        for (int i=0;i<N;i++) {
            j=i+1;
            while ((j<(N-1)) and (Vili[j].erk==Vili[j].ind)) {
                j++;
            }
            if (i<(N-1)) {
            cout << Vili[i].sor<<". allomas: "<<Vili[j].sor<<". allomas"<<endl;
            }
        }
    } else {
    cout << "Nincs tobb megallo"<<endl;
    }

    return 0;
}
