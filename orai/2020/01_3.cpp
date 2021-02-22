#include <iostream>
#include <iomanip>
#include <cmath> // ez ugyanaz, mint a C-s math.h

using namespace std;

int hanyjegyu(int sz) {
	int db = 0;

	while (sz != 0) {
		sz /= 10;
		db++;
	}

	return db;
}

int main() {
	cout << setprecision(4);
	for (double theta = 0; theta < 6; theta+=0.5) {
		cout << setw(10) << theta;
		cout << setw(10) << sin(theta);
		cout << setw(10) << cos(theta) << endl;
	}

	// adatok ki�r�sa
	cout << "2x2" << '=' << 4 << endl;

	// beolvas�s
	int szam;
	cout << "irj be egy szamot: ";
	cin >> szam;
	cout << "a beirt szam:" << szam << endl;

	// gyakorl�s: 1-t�l a szam-n�l nem nagyobb n�gyzetsz�mok 
	for (int i = 1; i * i <= szam; i++)
		cout << setw(5) << i * i << endl;

	// gyakorl�s: szam pr�mt�nyez�s felbont�sa
	int szel = hanyjegyu(szam);
	int o = 2;
	while (szam != 1) {
		while (szam % o != 0)
			o++;
		cout << setw(szel) << szam << '|' << o << endl;
		szam /= o;
	}
	cout << setw(szel) << 1 << '|' << endl;

	cin.get();
	cin.get();

	return 0;
}