#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct ido {
	int ora, perc, masodperc;
};

// k�vetkez� n�gyzetsz�m
void kovetkezo_negyzetszam(int &szam) {
	int gyok = sqrt(szam);
	gyok++;
	szam = gyok * gyok;
}

// pr�mteszt
bool primteszt(int szam) {
	for (int i = 2; i*i <= szam; i++)
		if (szam%i == 0)
			return false;
	return true;
}

// k�vetkez� pr�m
void kov_prim(int &szam) {
	do {
		szam++;
	} while (!primteszt(szam));
}

// id� ki�r�sa
void ido_kiir(const struct ido &t) {
	cout << t.ora << ":";
	cout << setfill('0') << setw(2) << t.perc << ":";
	cout << setfill('0') << setw(2) << t.masodperc << endl;
}

// sz�mot dupl�z (m�k�dik)
void duplaz(int &szam) {
	szam *= 2;
}

// dupl�z�s (pointerrel)
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

	// dupl�z�s 1. teszt
	int x = 4;
	duplaz(x);
	cout << "8-at varok: " << x << endl;

	// dupl�z�s 2. teszt
	x = 4;
	duplaz2(&x);
	cout << "8-at varok: " << x << endl;

	// id�
	struct ido most;
	most.ora = 9;
	most.perc = 16;
	most.masodperc = 4;
	ido_kiir(most);

	// n�gyzetsz�mok
	cout << "negyzetszamok:" << endl;
	for (int i = 0; i <= 100; kovetkezo_negyzetszam(i))
		cout << i << endl;

	// pr�msz�mok
	cout << "primszamok:" << endl;
	for (int i = 2; i <= 100; kov_prim(i))
		cout << i << endl;

	cin.get();
	return 0;
}