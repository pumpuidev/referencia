#include <iostream>
#include <time.h>
using namespace std;
const int maxn=8000;
int s[maxn],r[maxn];
    int elemszam;
    long int kezdet, veg, elteltido;
void masol();
void feltoltveletlennel();
void feltoltnovekedve();
void feltoltcsokkenve();
void feltoltmajdnemrendezve();
void oraindul();
void oraall();
void kiirasok(string cim);
void egyszerucseres();
void minimumkivalsztasos();
void buborek();
void javitottbuborek();
void beilleszteses();
void javitottbeilleszteses();
int main()
{   srand ( time(NULL) );
    elemszam=8000;
    feltoltveletlennel();
    //feltoltnovekedve();
    //feltoltcsokkenve();
    //feltoltmajdnemrendezve();
    egyszerucseres();
    minimumkivalsztasos();
    buborek();
    javitottbuborek();
    beilleszteses();
    javitottbeilleszteses();
    return 0;
}
void masol()
{for (int i=1;i<=elemszam;++i) r[i]=s[i];
    }
void feltoltveletlennel()
{for(int i=1;i<=elemszam;++i)
     {s[i] = rand() % elemszam + 1;
      r[i]=s[i]; }
 kiirasok("Feltölt véletlennel");
}
void feltoltnovekedve()
{   s[1] = rand() % elemszam + 1;
    r[1]=s[1];
    for(int i=2;i<=elemszam;++i)
     {s[i] = s[i-1]+rand() % 3;
      r[i]=s[i]; }
     kiirasok("Feltölt növekedve");
}

void feltoltcsokkenve()
{   s[1] = rand() % elemszam + 1;
     r[1]=s[1];
    for(int i=2;i<=elemszam;++i)
     {s[i] = s[i-1]-rand() % 3;
      r[i]=s[i]; }
     kiirasok("Feltölt csökkenve");
}

void feltoltmajdnemrendezve()
{   int j,k,sv;
    s[1] = rand() % elemszam + 1;
     r[1]=s[1];
    for(int i=2;i<=elemszam;++i)
     {s[i] = s[i-1]+rand() % 3;
      r[i]=s[i]; }
    for(int i=1;i<=elemszam/10;++i)
     { j= rand() % elemszam + 1;
       do { k= rand() % elemszam + 1;
       } while (j==k);
         sv=s[j];s[j]=s[k];s[k]=sv;
                 r[j]=r[k]; r[k]=sv;
    }
     kiirasok("Feltölt majdnem rendezve");
}

void oraindul()
{kezdet=clock();
    }
void oraall()
{veg=clock();
 elteltido=veg-kezdet;
    }
void kiirasok(string cim)
{system("cls");
cout<<cim<<endl;
for(int i=1;i<=elemszam;++i)
 {printf("%4d",i);printf(":%5d",r[i]);

   }
  cout<<"\nEltelt idõ:"<<elteltido<<endl;
  system("pause");
    }

void egyszerucseres()
{ oraindul();

    int s;
    for (int i=0;i<elemszam-1;++i){
        for (int j=i+1;j<elemszam;++j){
            if (r[i]> r[j]){
                s=r[i];r[i]=r[j];r[j]=s;
            }
        }
    }

  oraall();
  kiirasok("Egyszerû cserés");
  masol(); /* Az eredeti érték visszaállítása */
    }
void minimumkivalsztasos()
{ oraindul();

/*Ide jön az r rendezése */
  oraall();
  kiirasok("Minimumkiválasztásos");
  masol(); /* Az eredeti érték visszaállítása */
    }

void buborek()
{ oraindul();

/*Ide jön az r rendezése */
  oraall();
  kiirasok("Buborékos");
  masol(); /* Az eredeti érték visszaállítása */
    }
void javitottbuborek()
{ oraindul();

/*Ide jön az r rendezése */
  oraall();
  kiirasok("Javított buborékos");
  masol(); /* Az eredeti érték visszaállítása */
    }
void beilleszteses()
{ oraindul();

/*Ide jön az r rendezése */
  oraall();
  kiirasok("Beillesztéses");
  masol(); /* Az eredeti érték visszaállítása */
    }
void javitottbeilleszteses()
{ oraindul();

/*Ide jön az r rendezése */
  oraall();
  kiirasok("Javított beillesztéses");
  masol(); /* Az eredeti érték visszaállítása */
    }
