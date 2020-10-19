#include <iostream>

using namespace std;

int main()
{
    int elem;
    cout<<"Mennyi elemu legyen a tomb?"<<endl;
    cin>>elem;
    cout<<endl;
    int tomb[elem];
    cout<<"Adja meg a tomb elemeit: "<<endl;
    for (int i=0; i<elem; ++i){
        cout<<i+1<<" . elem: "<<endl;
        cin>>tomb[i];
        cout<<endl;
    }
    int ertekhatar;
    cout<<"adj meg egy felso hatart: ";
    cin>>ertekhatar;
    cout<<endl;

    int szam=0;
   for (int i=0; i<elem; ++i){
    if (tomb[i]>ertekhatar){
        cout<<tomb[i]<<endl;
            //szam=szam+tomb[i];
           // cout<<"Ennyi szam nagyobb az ertekhatarnal: "<<tomb[i]<<endl;
        }
        else {
            cout << "Az alabbi elemek ertekhatar felett vannak: " << endl;
    }

   }
 /*  int db=0;
  if (tomb[elem]>ertekhatar){
        db=db+1;
    cout<<"db ertekhatar"<<db<<endl;}
    else {cout<<"szar az egesz"<<endl;
   }

   int s=0;
   for (int i=0; i<tomb[elem];i++){
    s=s+tomb[elem];
    cout<<"ossz: "<<s<<endl;
   }
    int atlag=0;
    if (atlag>0){
            atlag=s/db;
        cout<<"atlag: "<<atlag<<endl;}
    else {cout<<"nincs adat";}*/
    int db=0;
    for (int i=0; i<elem; ++i){
        if (tomb[i]>ertekhatar)
            db++;
    }cout<<"nagyobb hatarnal: "<<db<<endl;


    double sum=0;
    for (int i=0; i<elem; ++i){
        sum=sum+tomb[i];
    }cout<<"osszeg: "<<sum<<endl;

    double avg=sum/elem;
    cout<<"atlag: "<<avg<<endl;

    int max=tomb[0];
    for (int i = 1; i<elem; ++i ){
        if (tomb[i]>max){
            max=tomb[i];
        }
    }cout<<"Max: "<<max<<endl;

    int min=tomb[0];
    for (int i = 1; i<elem; ++i ){
        if (tomb[i]<min){
            min=tomb[i];
        }
    }cout<<"Min: "<<min<<endl;
    return 0;
}
