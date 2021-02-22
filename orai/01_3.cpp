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
	// szám beolvasása
	int szam;
	cout << "irj be egy szamot: ";
	cin >> szam;

	int szamjegyek_szama = hanyjegyu(szam);

	// felbontás
	while(szam>1){
		// osztó keresése
		int oszto = 2;
		while (szam % oszto != 0)
			oszto++;

		// kiírás
		cout << setw(szamjegyek_szama) << szam << "|" << oszto << endl;

		// leosztás
		szam /= oszto;
	}
	cout << setw(szamjegyek_szama) << 1 << "|" << endl;

	cin.get();
	cin.get();

	return 0;
}