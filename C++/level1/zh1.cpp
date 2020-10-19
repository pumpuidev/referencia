#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int tomb[n];

    for (int i=0; i<n; ++i){
        cout<<"ez a tomb "<<i+1<<"-edik eleme"<<endl;
        cin>>tomb[i];

    }
    for (int i=0; i<n; ++i){
        cout<<"a tomb "<<i+1<<"-edikm eleme: "<<tomb[i]<<endl;

    }

    int ind=0;
    int max=0;
    for (int i=0; i<n-1; ++i){
        if (labs(tomb[i]-tomb[i+1])>max){
            max= labs(tomb[i]-tomb[i+1]);
            ind=i;
        }
    }

    cout<<"legnagyobb kuolnbseg: "<<max<<", ami az"<<ind<<"es az"<<ind+1<<"kozott van"<<endl;

    int hatar;
    cout<<"adja meg a hatart"<<endl;

    cin >>hatar;
    bool volt=true;
    int i=0;
    while (i<n && volt){
        if (tomb[i]>hatar){
            volt=false;
        }
        ++i;
    }
    if (volt){
        cout<<"igaz"<<endl;

    }else{cout<<"hamis";}

    return 0;
}
