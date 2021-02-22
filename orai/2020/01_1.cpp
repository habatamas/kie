#include <iostream> // std ki- �s bemenet
#include <iomanip> // ki- �s bemenet form�z�sa
#include <cmath> // ugyanaz, mint a C-s math.h

using namespace std; // n�vt�r

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
	
	// f�ggv�nyt�bla
	cout << setprecision(4);
	for (double theta = 0; theta < 10; theta += 1) {
		cout << setw(10) << theta;
		cout << setw(10) << sin(theta);
		cout << setw(10) << cos(theta) << endl;
	}

	// alap ki�r�s
	cout << "Hello MOGI!" << endl;
	cout << "2x2=" << 4 << " :)" << endl;

	// beolvas�s
	cout << "irj be egy szamot: ";
	int szam;
	cin >> szam;
	cout << "a szam amit beirtal: " << szam << endl;

	// 1-t�l a szam-n�l nem nagyobb n�gyzetsz�mok
	cout << "negyzetszamok:" << endl;
	for (int i = 1; i * i <= szam; i++)
		cout << setw(10) << i * i << endl;

	// pr�mt�nyez�s felbont�s
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