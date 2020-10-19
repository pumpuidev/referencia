#include <iostream>

using namespace std;

const int MAXN = 50;
const int MAXT = 20;

struct product{
    string name;
    int price;
    string manuf;
};

struct sales{
    int thing, amount;
};

void read(product[], sales[], int&, int&);

int felA(product[], sales[], const int, const int);
void felB(product[], sales[], const int, const int, int[]);
int felC(product[], sales[], const int, const int);
int felD(product[], sales[], const int, const int, int[]);

int main() {

    product element[MAXT];
    sales sale[MAXN];
    int n, t;
    read(element, sale, n, t);
    int megB[MAXT] = {0};
    int megD[MAXT] = {0};

    int megA = felA(element, sale, n, t);
    felB(element, sale, n, t, megB);
    int megC = felC(element, sale, n, t);
    int dbD = felD(element, sale, n, t, megD);

    cout << megA << endl;
    for (int i = 0; i < t; ++i)
        cout << megB[i] << ' ';
    cout << endl;
    cout << element[megC].name << ';' << element[megC].manuf << endl;
    cout << dbD;
    for (int i = 0; i < t; ++i) {
        if (megD[i] != 0) {
            cout << ';' << element[megD[i] -1].manuf;
        }
    }

    return 0;

}

void read(product element[], sales sale[], int& n, int& t) {

    string tmp;
    int i = 0;
    int k = 0;
    cin >> n; cin >> t;
    getline(cin, tmp);

    while (i < t) {
        getline(cin, element[k].name);
        cin >>  element[k].price;
        getline(cin, tmp);
        getline(cin, element[k].manuf);

        ++i; ++k;
    }

    for (int i = 0; i < n; ++i) {
        cin >> sale[i].thing; cin >> sale[i].amount;
    }
}

int felA(product element[], sales sale[], const int n, const int t) {

    int result = 0;

    for (int i = 0; i < n; ++i) {
        result += (sale[i].amount * element[sale[i].thing -1].price);
    }

    return result;

}

void felB(product element[], sales sale[], const int n, const int t, int megB[]) {

    for (int i = 0; i < n; ++i)
        megB[sale[i].thing -1] += sale[i].amount;

}

int felC(product element[], sales sale[], const int n, const int t) {

    int result = -1;
    int minC = 0;
    bool l = false;

    for (int i = 0; i < n; ++i) {
        if (sale[i].amount >= 0) {}
        else if (sale[i].amount < 0 && !l) {
            l = true;
            minC = (sale[i].amount * element[sale[i].thing -1].price);
            result = (sale[i].thing -1);
        } else if (sale[i].amount < 0 && l) {
            if (sale[i].amount * element[sale[i].thing -1].price < minC) {
                minC = (sale[i].amount * element[sale[i].thing -1].price);
                result = (sale[i].thing -1);
            }
        }
    }

    return result;

}

int felD(product element[], sales sale[], const int n, const int t, int megD[]) {

    int result = 0;

        for (int i = 0; i < n; ++i) {
            if (sale[i].amount > 0) {
                megD[sale[i].thing -1]++;
            }
        }

        for (int i = 0; i < t; ++i) {
            if (megD[i] != 0) result++;
        }

    return result;

}


