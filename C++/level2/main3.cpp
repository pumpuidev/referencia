#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
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

    vector<int> t(n);
    for (int i=0;i<t.size();++i){
        do{
            cin>>t[i];
            hiba=cin.fail();
            cin.clear();
            cin.ignore(1000,'\n');
        }
        while(hiba);
    }

    for(int i=0;i<t.size();++i){
        cout<<t[i]<<endl;
    }


    return 0;
}
