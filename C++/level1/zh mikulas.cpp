#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int maxN=100;

struct Rendeles{
	int szam;
	string nev;
};

bool beolvas(Rendeles t[], int &N);
void kiir (Rendeles t[], int N);
int B_feladat(Rendeles t[], int N, int db);
int C_feladat(Rendeles t[], int N);//indexszel ter vissza
int D_feladat(Rendeles t[], int N, int kiv[]);

int main (){
    Rendeles t[maxN];
    int kiv[maxN];
    int N;
    int temp, temp2;
    bool good=beolvas(t, N);
    if (good){
        cout <<"A\n";
        kiir(t, N);
        cout<<"B\nmegszamlalas tetel\n";
        cout<<B_feladat(t, N, 20);
        cout<< "\nC\nmaximum kivalasztas\n";
        temp=C_feladat(t, N);
        cout<<t[temp].szam<<endl;
        cout<<"D\nKivalogatas tetel\n";
        temp=D_feladat(t, N, kiv);
        for (int i=0;i<temp;i++){
            temp2=kiv[i];
            cout<<t[temp2].nev<<" "<<t[temp2].szam<<endl;
        }
    }


}
bool beolvas(Rendeles t[], int &N){
	const string fname="miki.be";
	ifstream f(fname.c_str());
	if (f.is_open()){
		f>>N;
		for (int i=0;i<N;i++){
            f>>t[i].szam>>t[i].nev;
		}
		f.close();
		return true;}
	else {
		"Nem sikerült a beolvasas.";
		return false;
	}
}
void kiir (Rendeles t[], int N){
    for (int i=0;i<N;i++){
            cout<<t[i].szam<<" "<<t[i].nev<<endl;
		}
}
int B_feladat(Rendeles t[], int N, int db){
    //hanyszor kell ordulni a mikulasnak, ha egy foeduloval db ajandekot tud vinni magaval
    ///megszamlalas tetel
    int s=0;
    for (int i=0;i<N;i++){
        s+=t[i].szam;
    }
    bool maradek= s%db!=0;
    s= s-(s%db);
    if (maradek){
    return s/db+1;}
    else{
    return s/db;}
}
int C_feladat(Rendeles t[], int N){
    //max.kiv
    int max=0;
    for (int i=1;i<N;i++){
        if (t[max].szam<t[i].szam){
            max=i;
        }
    }
    return max;
}
int D_feladat(Rendeles t[], int N, int kiv[]){
    int db=0;
    for (int i=0; i<N;i++){
        if (t[i].szam>=5){
            kiv[db]=i;
            db++;
        }
    }
    return db;
}
/* minta bemenet
5
3 Szlávi
3 Nagy
10 Betyár
5 Papp
3 Balogh
*/
/* minta kimenet
A
Szlávi 3
Nagy 3
Betyár 10
Papp 5
Balogh 3
B
tetel neve
2
C
tetel neve
10
D
tetel neve
2
Betyár 10
Papp 5
*/
