#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> t;

    cout << "Hany db elem lesz?" << endl;

    bool hiba;
    do{
        cin>>n;
        hiba = cin.fail() || n<0 ;
        if (hiba){
        cin.clear();
        cin.ignore(1000,'\n');
        }
    }
    while(hiba);

    int m;
    cin>>m;

    cout<<n<<" "<<m;

    return 0;
}
