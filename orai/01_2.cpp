#include <iostream>
#include <iomanip>

using namespace std;

void duplaz1(int szam) { // �rt�k szerinti param�ter�tad�s
	szam = szam * 2;
}

int duplaz2(int szam) { // �rt�k szerinti param�ter�tad�s
	return 2 * szam;
}

void duplaz3(int *p) { // �rt�k (pointer) szerinti param�ter�tad�s
	*p *= 2;
}

void duplaz4(int& r) { // referencia szerinti param�ter�tad�s
	r *= 2;
}

struct datum {
	int ev, ho, nap;
};

// konstans referencia
void datum_kiir(const datum &d) { // nem kell ki�rni a struct-ot
	cout << setfill('0');
	cout << d.ev << "." << setw(2) << d.ho << "." << setw(2) << d.nap << "." << endl;
}

int main() {
	cout << "hello" << endl;

	datum ma;
	ma.ev = 2021;
	ma.ho = 2;
	ma.nap = 8;
	datum_kiir(ma);

	int szam = 10;

	// ez nem j�
	duplaz1(szam);
	cout << szam << endl;

	// ez m�r j�
	cout << duplaz2(szam) << endl;

	// pointeres megold�s
	duplaz3(&szam);
	cout << szam << endl;

	// referenci�s megold�s
	duplaz4(szam);
	cout << szam << endl;

	int szam2 = 123;
	duplaz4(szam2);
	cout << szam2 << endl;

	// C:   scanf("%d", &szam);
	// C++: cin >> szam;

	return 0;
}