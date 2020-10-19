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
 kiirasok("Felt�lt v�letlennel");
}
void feltoltnovekedve()
{   s[1] = rand() % elemszam + 1;
    r[1]=s[1];
    for(int i=2;i<=elemszam;++i)
     {s[i] = s[i-1]+rand() % 3;
      r[i]=s[i]; }
     kiirasok("Felt�lt n�vekedve");
}

void feltoltcsokkenve()
{   s[1] = rand() % elemszam + 1;
     r[1]=s[1];
    for(int i=2;i<=elemszam;++i)
     {s[i] = s[i-1]-rand() % 3;
      r[i]=s[i]; }
     kiirasok("Felt�lt cs�kkenve");
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
     kiirasok("Felt�lt majdnem rendezve");
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
  cout<<"\nEltelt id�:"<<elteltido<<endl;
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
  kiirasok("Egyszer� cser�s");
  masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
    }
void minimumkivalsztasos()
{ oraindul();

/*Ide j�n az r rendez�se */
  oraall();
  kiirasok("Minimumkiv�laszt�sos");
  masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
    }

void buborek()
{ oraindul();

/*Ide j�n az r rendez�se */
  oraall();
  kiirasok("Bubor�kos");
  masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
    }
void javitottbuborek()
{ oraindul();

/*Ide j�n az r rendez�se */
  oraall();
  kiirasok("Jav�tott bubor�kos");
  masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
    }
void beilleszteses()
{ oraindul();

/*Ide j�n az r rendez�se */
  oraall();
  kiirasok("Beilleszt�ses");
  masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
    }
void javitottbeilleszteses()
{ oraindul();

/*Ide j�n az r rendez�se */
  oraall();
  kiirasok("Jav�tott beilleszt�ses");
  masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
    }
