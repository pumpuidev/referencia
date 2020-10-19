#include <iostream>
#include <cstdlib>

using namespace std;

struct Kiraly {
    int kezdete, vege;
    string nev;
};

int main()
{
    int n;
    cin >> n;
    Kiraly t [n];
    for (int i = 0; i < n; i++) {
        Kiraly x;
        string s;
        std::getline(std::cin,s);
        string seged = "";
        int db = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                db++;
                switch(db) {
                    case 1: x.kezdete = atoi(seged.c_str());
                        break;
                    case 2: x.vege = atoi(seged.c_str());
                        break;
                }
                seged = "";
            }
            else seged = seged + s[i];
            if (i == s.length() - 1) atoi(seged.c_str());
        }
    }
    int a;
    cin >> a;
    int db = 0;
    string o[a];
    for (int i = 0; i < a; i++) {
        string y;
        cin >> y;
        cin >> y;
        o[i] = y;
    }

    int p = 0;
    for (int i = 0; i < a; i++) {
        bool vanE = false;
        for (int j = 0; j < n; j++) {
            if (t[j].nev == o[i]) vanE = true;
        }
        if (vanE == false) p++;
    }
    cout << p;
    return 0;
}
