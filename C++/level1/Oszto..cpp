
//Feladat:  Term�szetes sz�m legkisebb 1-t�l k�l�nb�z� oszt�j�t
#include <iostream>

using namespace std;

int main()
{   int N,i,O;

    cout << "Termeszetes szam 1-tol kulonbozo legkisebb osztoja" << endl<<endl;
    do{
        cout<<"Kerek egy termeszetes szamot!"<<endl;
        cin>>N;
    }while (N<=1);  //el�felt�tel szerint N>1

    i=2;
    while ((N % i)!=0){
        i=i+1;      //gyorsabb lenne az i++ haszn�lata
    }
    O=i;

    cout<<N<<" legkisebb 1-tol kulonbozo osztoja "<<O<<endl;

    return 0;
}
