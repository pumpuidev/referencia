#include <iostream>

using namespace std;



int main() {

int guess;
bool hiba = false;

cout << "Melyik szamra gondoltal?: ";
cin >> guess;


hiba = (guess <= 0 || cin.fail());


if (!(hiba)) cout << guess;
else return 1;

return 0; }


/*int main()
{
    int a=0;
    cin>>a;
    if (a / 1)
    cout<<a;
    else cout<<"nem egesz";
    return 0;
}*/
