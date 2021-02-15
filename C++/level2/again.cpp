#include <iostream>//header file
#include <stdio.h>
#include <vector>

using namespace std;
namespace nevter
{
class osztaly
{
public:
    string osztfgvstring;
};
int szam;
}
void fgv2();//fgv megivas
int main()
{
    int x=0;
    do//do while ciklus
    {
        cout<<x<<" mukodik a ciklusom csak szar az indexelesem"<<endl;
        x++;
    }
    while(x<5);
    int y=1;
    do//do while ciklus
    {
        cout<<y<<" mukodik a ciklusom"<<endl;
        y++;
    }
    while(y<6);
    fgv2();//void fgv
    nevter::szam=0;
    cout<<nevter::szam<<" mukodik a nevterem"<<endl;
    nevter::osztaly doboz;
    doboz.osztfgvstring="mukodik a class is";
    cout<<doboz.osztfgvstring<<endl;

    return 0;
}
void fgv2() //fgv declaralas
{
    cout<<"void fgv2 mukodik a kulso fuggvenyem"<<endl;
}
