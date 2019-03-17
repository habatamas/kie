#include <iostream>
#include <iomanip> // formázáshoz
#include <cmath>

using namespace std;

// fokból radiánba
double deg2rad(double deg) {
	return deg / 180 * acos(-1);
}

// 1-tõl n-ig számok
int *szamok(int n) {
	// memóriafoglalás
	int *tomb = new int[n];

	// feltöltjük számokkal
	for (int i = 1; i <= n; i++)
		tomb[i-1] = i;

	// visszatérés a foglalt tömbbel
	return tomb;
}

int main() {
	cout << "Hello MOGI" << endl;

	// változó beolvasása
	int szam;
	cout << "Irj be egy szamot: ";
	cin >> szam;
	cout << "A beirt szam: " << szam << endl;

	// fix szélesség
	for (int i = 1; i <= 100000; i *= 10) {
		cout << setfill('0') << setw(10) << i << endl;
	}

	// tizedesjegyek száma
	for (double x = 0.123102342; x < 10; x += 0.987126313213) {
		cout << setprecision(3) << x << endl;
	}

	// függvénytábla
	cout << setfill(' ');
	for (double szog = 0; szog <= 360; szog += 5) {
		cout << setw(5) << szog;
		cout << setw(15) << sin(deg2rad(szog));
		cout << setw(15) << cos(deg2rad(szog)) << endl;
	}

	// dinamikus memóriakezelés teszt
	int *t = szamok(10);
	for (int i = 0; i < 10; i++) {
		cout << t[i] << endl;
	}
	delete[] t;

	cin.get();
	cin.get();
	return 0;
}