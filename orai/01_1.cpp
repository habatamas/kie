#include <iostream>
#include <iomanip> // form�z�shoz
#include <cmath>

using namespace std;

// fokb�l radi�nba
double deg2rad(double deg) {
	return deg / 180 * acos(-1);
}

// 1-t�l n-ig sz�mok
int *szamok(int n) {
	// mem�riafoglal�s
	int *tomb = new int[n];

	// felt�ltj�k sz�mokkal
	for (int i = 1; i <= n; i++)
		tomb[i-1] = i;

	// visszat�r�s a foglalt t�mbbel
	return tomb;
}

int main() {
	cout << "Hello MOGI" << endl;

	// v�ltoz� beolvas�sa
	int szam;
	cout << "Irj be egy szamot: ";
	cin >> szam;
	cout << "A beirt szam: " << szam << endl;

	// fix sz�less�g
	for (int i = 1; i <= 100000; i *= 10) {
		cout << setfill('0') << setw(10) << i << endl;
	}

	// tizedesjegyek sz�ma
	for (double x = 0.123102342; x < 10; x += 0.987126313213) {
		cout << setprecision(3) << x << endl;
	}

	// f�ggv�nyt�bla
	cout << setfill(' ');
	for (double szog = 0; szog <= 360; szog += 5) {
		cout << setw(5) << szog;
		cout << setw(15) << sin(deg2rad(szog));
		cout << setw(15) << cos(deg2rad(szog)) << endl;
	}

	// dinamikus mem�riakezel�s teszt
	int *t = szamok(10);
	for (int i = 0; i < 10; i++) {
		cout << t[i] << endl;
	}
	delete[] t;

	cin.get();
	cin.get();
	return 0;
}