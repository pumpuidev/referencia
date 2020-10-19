//Feladat:
//  V�letlen tesztadatok gener�l�sa f�jlba, a "tengeres" feladatokhoz.
//Specifik�ci�:
//  Be: N ELEME EG�SZ [tesztadatok sz�ma]
//      NEu,NAm ELEME EG�SZ [Eur�p�ra, Amerik�ra es� m�r�si adatok "v�rhat�" sz�ma]
//      PSzig ELEME VAL�S [szigetre es�s val�sz�n�s�ge]
//      MaxMag ELEME EG�SZ [a gener�lhat� legnagyobb magass�g]
//  Ki: Mag ELEME T�MB[1..N:EG�SZ]
//  Ef: NEu,NAm>=1 �S N>=NEu+NAm �S
//      PSzig ELEME [0..1) �S
//      MaxMag>0
//  Uf: Mag[1],Mag[N] ELEME [1..MaxMag] �S
//      L�TEZIK eu ELEME [1..NEu]: L�TEZIK am ELEME [1..NAm]:
//         B�RMELY i ELEME [1..eu]: Mag[i] ELEME [1..MaxMag] �S Mag[eu+1]=0 �S
//         B�RMELY i ELEME [N-am+1..N]: Mag[i] ELEME [1..MaxMag] �S Mag[am-1]=0 �S
//         B�RMELY i ELEME [eu+1..N-am]: Mag[i] ELEME [0..MaxMag]
//  Megjegyz�s: nem foglalkoztunk val�sz�n�s�gi elv�r�sokkal!

#include <iostream>
#include <fstream>
//#include <time.h>//csak a 'srand(time(NULL))' rand()-inicializ�l�shoz kell!
#include <stdlib.h>//Code::Blocks 10.05-h�z m�r kell a system kedv��rt

using namespace std;

//Param�terbeolvas�s:
//beolvassa a mnN..mxN k�z�tti eg�sz sz�mot (mxN<mnN => v�gtelen)
void be_int(string kerd, int &n, int mnN, int mxN, string uz);
//beolvassa a mnN..mxN k�z�tti val�s sz�mot (mxN<mnN => v�gtelen)
void be_float(string kerd, float &x, float mnN, int mxN, string uz);
//F�jlba gener�l�s:
void fajlbaGeneralas(string fN, int n, int nEu, int nAm, float pT, int mxM);
void billentyureVar();

int main()
{
    //Bemenet:
    int N,NEu,NAm,MaxMag;
    float PSzig;
    //Kimenet:
    const string fN="tenger.csv";//kimeneti f�jl neve

    //srand(time(NULL));//rand()-inicializ�l�shoz kell!
    //adatok beolvas�sa:
    be_int("Europai pontok (varhato) szama",NEu,1,0,"Hibas termeszetes szam!");
    be_int("Amerikai pontok (varhato) szama",NAm,1,0,"Hibas termeszetes szam!");
    be_int("Meresi pontok szama",N,NEu+NAm,0,"Hibas termeszetes szam!");
    be_float("Tengeri pontok valoszinusege",PSzig,0,1,"Hibas valos szam!");
    be_int("Legnagyobb magassag",MaxMag,1,0,"Hibas termeszetes szam!");

    //a l�nyeg:
    fajlbaGeneralas(fN,N,NEu,NAm,PSzig,MaxMag);

    billentyureVar();
    return 0;
}

//F�jlba gener�l�s:
void fajlbaGeneralas(string fN, int n, int nEu, int nAm, float pT, int mxM)
//Uf: N sorban, soronk�nt egyetlen 0..mxM k�z�tti eg�sz sz�m ...
//    l. m�g a fenti Uf-t
{
    ofstream oF(fN.c_str());
    int eu=rand()%nEu+1;//Eur�pa hossza
    int am=rand()%nAm+1;//Amerika hossza
    for(int i=1;i<=eu;++i)
    {
      oF << rand()%mxM+1 << endl;
    }
    //TODO: lehet, h. Eur�p�nak m�g nincs v�ge!
    for(int i=eu+1;i<=n-am;++i)
    {
      if (rand()/(RAND_MAX+1.0)<pT)
      {
        oF << rand()%mxM+1 << endl;
      }
       else
      {
        oF << 0 << endl;
      }
    }
    //TODO: lehet, h. Amerika m�r elkezd�d�tt!
    for(int i=n-am+1;i<=n;++i)
    {
      oF << rand()%mxM+1 << endl;
    }
    oF.close();
}

//beolvassa a mnN..mxN k�z�tti eg�sz sz�mot (mxN<mnN => v�gtelen)
void be_int(string kerd, int &n, int mnN, int mxN, string uz)
{
    bool hiba;
    string tmp;

    do{
      if (mxN>=mnN)
      {
        cout << kerd << " (" << mnN << ".." << mxN << "):"; cin >> n;
        hiba=cin.fail() || n<mnN || n>mxN;
      }
        else
      {
        cout << kerd << " (" << mnN << "..):"; cin >> n;
        hiba=cin.fail() || n<mnN;
      }
      if (hiba)
      {
        cout << uz << endl;
        cin.clear(); getline(cin,tmp,'\n');
      }
    }while(hiba);
}

//beolvassa a mnN..mxN k�z�tti val�s sz�mot (mxN<mnN => v�gtelen)
void be_float(string kerd, float &x, float mnN, int mxN, string uz)
{
    bool hiba;
    string tmp;

    do{
      if (mxN>=mnN)
      {
        cout << kerd << " (" << mnN << ".." << mxN << "):"; cin >> x;
        hiba=cin.fail() || x<mnN || x>mxN;
      }
        else
      {
        cout << kerd << " (" << mnN << "..):"; cin >> x;
        hiba=cin.fail() || x<mnN;
      }
      if (hiba)
      {
        cout << uz << endl;
        cin.clear(); getline(cin,tmp,'\n');
      }
    }while(hiba);
}

void billentyureVar()
{
    system("pause");
}
