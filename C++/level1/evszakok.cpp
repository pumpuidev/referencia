#include <iostream>
#include <string>

using namespace std;



int main() {
	string honapok[12]={"december","januar","februar","marcius","aprilis","majus","junius","julius","augusztus","szeptember","oktober","november"};
	string evszakok[4]={"tel","tavasz","nyar","osz"};
	string be;
	cout << "adj meg egy honapot: ";
	cin >> be;
	for(int i=0;i<12;i++)
		if(be==honapok[i])
			cout << evszakok[i/3] << endl;

	return 0;
}
