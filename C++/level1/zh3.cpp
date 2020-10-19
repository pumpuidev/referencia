#include <iostream>

using namespace std;

struct House{
    int price;
    int square;
};

int main()
{
   int n;
   cin >> n;
   House houses[n];

   int aa=0;
    cin >> aa;
        int b=0;
    cin>>b;

    int c=0;
    cin>>c;

          int d=0;
        cin>>d;

              int k=0;
        cin>>k;

              int idealar=0;
        cin>>idealar;

                int idealmeret=0;
        cin>>idealmeret;

   for (int i = 0; i< n; ++i){
    cin >> houses[i].price;
        cin >> houses[i].square;
   }



        bool l=false;

   for (int i =0; i<n && !l;++i){

    if (houses[i].price > b && houses[i].square > aa){
     // cout<<" "<<houses[i].price<<" "<<houses[i].square;
     cout << i+1 << endl;
     l=true;
    }
   }
//cout << "ddd" << endl;
   if (!l){
    cout << 0 << endl;

   }

   int ar=0;
   for (int i=0; i<n; ++i){
    ar = ar+houses[i].price;
   }
   ar=ar/n;

    int count = 0;
    for (int i =0; i<n ;++i){

    if (houses[i].price < ar && houses[i].square > aa){
     // cout<<" "<<houses[i].price<<" "<<houses[i].square;

    count++;
    }

   }
   cout << count << " ";
   for (int i =0; i<n ;++i){

    if (houses[i].price < ar && houses[i].square > aa){
     // cout<<" "<<houses[i].price<<" "<<houses[i].square;
    cout << i+1 << " ";

    }

   }
   cout << endl;
cout<<endl;
cout<<endl;
cout<<endl;
    return 0;
}
