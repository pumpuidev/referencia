#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> t;

    cout << "Hany db elem lesz?" << endl;

    do{
        cin.clear();
        cin.ignore(1000,'\n');
        cin>>n;
    }
    while(cin.fail() || n<0 );


    cin>>n;

    return 0;
}
