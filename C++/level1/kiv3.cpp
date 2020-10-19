#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Kerem adja a meg a futok szamat: ";
    cin>>n;
    cout << endl;

    int futok[n];
    cout<<"Kerem adja a meg a futok eredményeit: ";
    for (int i=0; i<n; i++){
        cout <<i << "-edik futo: ";
        cin>>futok[i];
        cout << endl;
    }
    int c=0;


    for (int i=0; i<n; i++){
        cout<<futok[i]<<" ";
    }
    int hatar;
    cout<<"kerem adja meg a szinthatart"<<endl;
    cin>>hatar;
  /*  for (int i=0; i<n; i++){
        if (futok[i]>hatar){
            cout<<futok[i]<<endl;
            c=c+1;
            cout<<"osszeg: "<<c<<endl;
        }
        else {
            cout << i << "edik futo a hatar alatt van : " << futok[i]<< endl;
        }
    }*/
    int i =0;
    while (i < n ){
         if (futok[i]>hatar){
            cout<<futok[i]<<endl;
            c=c+1;
            cout<<"osszeg: "<<c<<endl;
        }
        else {
            cout << i << "edik futo a hatar alatt van : " << futok[i]<< endl;
        }
        i++;
    }

    cout << "Hello world!" << endl;
    return 0;
}
