#include <iostream> // std ki- és bemenet
#include <iomanip> // ki- és bemenet formázása
#include <cmath> // ugyanaz, mint a C-s math.h

using namespace std; // névtér

int hanyjegyu(int sz) {
	if (sz == 0) return 1;

	int cnt = 0;
	while (sz != 0) {
		cnt++;
		sz /= 10;
	}
	return cnt;
}

int main() {
	
	// függvénytábla
	cout << setprecision(4);
	for (double theta = 0; theta < 10; theta += 1) {
		cout << setw(10) << theta;
		cout << setw(10) << sin(theta);
		cout << setw(10) << cos(theta) << endl;
	}

	// alap kiírás
	cout << "Hello MOGI!" << endl;
	cout << "2x2=" << 4 << " :)" << endl;

	// beolvasás
	cout << "irj be egy szamot: ";
	int szam;
	cin >> szam;
	cout << "a szam amit beirtal: " << szam << endl;

	// 1-tõl a szam-nál nem nagyobb négyzetszámok
	cout << "negyzetszamok:" << endl;
	for (int i = 1; i * i <= szam; i++)
		cout << setw(10) << i * i << endl;

	// prímtényezõs felbontás
	int szelesseg = hanyjegyu(szam);
	int oszt = 2;
	while (szam != 1) {
		while (szam % oszt != 0)
			oszt++;

		cout << setw(szelesseg) << szam << '|' << oszt << endl;
		szam /= oszt;
	}



	cin.get();
	cin.get();

	return 0;
}