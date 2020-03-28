#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct ido {
	int ora, perc, masodperc;
};

// következõ négyzetszám
void kovetkezo_negyzetszam(int &szam) {
	int gyok = sqrt(szam);
	gyok++;
	szam = gyok * gyok;
}

// prímteszt
bool primteszt(int szam) {
	for (int i = 2; i*i <= szam; i++)
		if (szam%i == 0)
			return false;
	return true;
}

// következõ prím
void kov_prim(int &szam) {
	do {
		szam++;
	} while (!primteszt(szam));
}

// idõ kiírása
void ido_kiir(const struct ido &t) {
	cout << t.ora << ":";
	cout << setfill('0') << setw(2) << t.perc << ":";
	cout << setfill('0') << setw(2) << t.masodperc << endl;
}

// számot dupláz (mûködik)
void duplaz(int &szam) {
	szam *= 2;
}

// duplázás (pointerrel)
void duplaz2(int *p) {
	*p *= 2;
}

int main() {
	cout << "hello" << endl;

	int a;
	int &r = a;

	r = 10;
	cout << a << endl;

	a = 9;
	cout << r << endl;

	// duplázás 1. teszt
	int x = 4;
	duplaz(x);
	cout << "8-at varok: " << x << endl;

	// duplázás 2. teszt
	x = 4;
	duplaz2(&x);
	cout << "8-at varok: " << x << endl;

	// idõ
	struct ido most;
	most.ora = 9;
	most.perc = 16;
	most.masodperc = 4;
	ido_kiir(most);

	// négyzetszámok
	cout << "negyzetszamok:" << endl;
	for (int i = 0; i <= 100; kovetkezo_negyzetszam(i))
		cout << i << endl;

	// prímszámok
	cout << "primszamok:" << endl;
	for (int i = 2; i <= 100; kov_prim(i))
		cout << i << endl;

	cin.get();
	return 0;
}