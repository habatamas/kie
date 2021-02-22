#include <iostream>
#include <iomanip>

using namespace std;

int hanyjegyu(int szam) {
	int szjegyek = 0;

	while (szam>0) {
		szam /= 10;
		szjegyek++;
	}

	return szjegyek;
}

int main() {
	// sz�m beolvas�sa
	int szam;
	cout << "irj be egy szamot: ";
	cin >> szam;

	int szamjegyek_szama = hanyjegyu(szam);

	// felbont�s
	while(szam>1){
		// oszt� keres�se
		int oszto = 2;
		while (szam % oszto != 0)
			oszto++;

		// ki�r�s
		cout << setw(szamjegyek_szama) << szam << "|" << oszto << endl;

		// leoszt�s
		szam /= oszto;
	}
	cout << setw(szamjegyek_szama) << 1 << "|" << endl;

	cin.get();
	cin.get();

	return 0;
}