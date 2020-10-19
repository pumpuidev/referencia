#include <iostream>

using namespace std;

typedef struct {
    double x,y;
     } TPont;

const int MAXN = 100;

void beolvas(int &n, TPont p[MAXN], TPont &kkp, double &kr) {
    cout << "N: ";
    cin >> n;



    for (int i=0; i<=n-1; i++){
            cout << i+1 << ". x: ";
    cin >> p[i].x;
    cout << i + 1 << ". y: ";
    cin >> p [i].y;

    }

    cout << "kor kp x: ";
    cin >> kkp.x;
    cout << "kor kp y: ";
    cin >> kkp.y;
    cout << "Kor sugara: ";
    cin >> kr;


    }

  void megszamol(const int n, const TPont p[MAXN], const TPont kkp, const double kr, int &db){
  db = 0;
  for (int i = 0; i<=n-1; i++){
    if ((p[i].x-kkp.x)*(p[i].x-kkp.x) +
        (p[i].y-kkp.y)*(p[i].y-kkp.y) <= kr*kr
        ){
            db=db+1;
        }
  }
  }

void kiir(const int db) {
cout << "Benne: " << db << endl;
}

int main()
{   // 1
    int n;
    TPont p[MAXN];
    TPont kkp;
    double kr;
    int db;

    beolvas(n, p, kkp, kr); //be
    megszamol(n, p, kkp, kr, db); //be-->> ki
    kiir(db); //ki



    return 0;
}
