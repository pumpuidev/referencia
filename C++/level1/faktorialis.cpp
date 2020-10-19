#include <iostream>


using namespace std;

int main()
{
  //1. dekl
  int n;
  int f;
  //2. beolv.

/* do {
ciklusmag
  } while (felt);
  */
  bool rossz;
  do {
      cout << "N: ";
  cin >> n;
  rossz = !(n>=0);
  if (rossz) {
    cout << "N neg" << endl;
  }
  } while (rossz);

  //3. feldolgozas
  f = 1;
  for (int i = 1 /*tol*/; i <= n; i++) {
    f = f * i;
  }
  //4. kiiras
  cout << "Fakt = " << f << endl;
    return 0;
}
