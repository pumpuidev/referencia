#include <iostream>
#include <fstream>
#include <sstream>
#include "enor_string.h"
#include "enor_file.h"

using namespace std;

int mondathossz(string mondat);

int main()
{
	//1. irjuk ki seqoutfile-ba ezt a szoveget csupa nagybetuvel
	string bemenet = "Du. Du hast. Du hast mich. Du hast mich gefragt. Und ich hab nichts gesagt.";

	//erdemes mindig irni egy gyors ellenorzest, hogy jo-e a felsorolo...
//	Enor_string t(bemenet);
//	for(t.First();!t.End();t.Next())
//        cout<<t.Current();
//    cout<<endl;

    ofstream ofs("ki.txt");
    Enor_string t(bemenet);
	for(t.First();!t.End();t.Next())
        ofs<<(char)toupper(t.Current());    //charra kell konvertalni, kulonben az ASCII-kodjat irna ki

	//2. irjuk ki a konzolra a fajl tartalmat csupa nagybetuvel
	//Enor_file tf("asd.txt");	//erre hibas, nem csinal semmit -> First utan mar igaz az End
	Enor_file tf("be.txt");

	for(tf.First();!tf.End();tf.Next())
        cout<<(char)toupper(tf.Current());    //charra kell konvertalni, kulonben az ASCII-kodjat irna ki
    cout<<endl;

	//3/a. mondjuk meg, hany 20 betusnel hosszabb mondat van a fajlban (mondatok felsorolasaval)
	//Enor_mondat tm("be.txt");
	int c = 0;
	cout<<c<<endl;

	//3/b. mondjuk meg, hany 20 betusnel hosszabb mondat van a fajlban (mondathosszak felsorolasaval)
	//Enor_mondathossz tmh("be.txt");
	int ch = 0;
	cout<<ch<<endl;

    return 0;
}
