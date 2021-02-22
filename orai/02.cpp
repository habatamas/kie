#include <iostream>

using namespace std;

// maradékosan osztó függvény
// be: osztandó, osztó
// ki: hányados, maradék
void maradekos_osztas(int osztando, int oszto, int &hanyados, int &maradek) {
	hanyados = osztando / oszto;
	maradek = osztando % oszto;
}

// bármilyen tömbben keresünk egy értéket
// térjen vissza a találat pointerével, vagy
// ha nincs találat, akkor null pointerrel
template<typename T>
T* keres(T* t, int db, T keresett, int k=1) {
	int hanyadik = 0;
	for (int i = 0; i < db; i++) {
		// megtaláltuk?
		if (t[i] == keresett) {
			// van találat
			hanyadik++;

			// ez a találat kellett?
			if (hanyadik == k) {
				return &(t[i]); // találat pointere
			}
		}
	}

	// ha nincs találat
	return nullptr; // C-ben: NULL
}

// dátum
struct datum {
	int ev, ho, nap;
};

// dátum kiíró
void kiir(const datum &d) {
	cout << d.ev << "." << d.ho << "." << d.nap << endl;
}

// idõ
struct ido {
	int ora, perc;
};

// idõ kiíró
void kiir(const ido& i) {
	cout << i.ora << ":" << i.perc << endl;
}

// hibás fv. túlterhelés:
/*
int fv() {
	return 0;
}
double fv() {
	return 0.0;
}
*/

void fv(int a, int b = 0) {
}
void fv(double a, double b = 0) {
}

// 3d-s vektor
struct vektor3d {
	double x, y, z;
};

void kiir(const vektor3d& v) {
	cout << "[" << v.x << "; " << v.y << "; " << v.z << "]" << endl;
}

// operator overload
vektor3d operator+(const vektor3d& v1, const vektor3d& v2) {
	vektor3d osszeg;
	osszeg.x = v1.x + v2.x;
	osszeg.y = v1.y + v2.y;
	osszeg.z = v1.z + v2.z;
	return osszeg;
}

// sablon függvények
template<typename T1, typename T2>
void fv(T1 a, T2 b) {
	int c = (int)a;
}

// minimumkeresés tömbben
template<typename T>
T minimum_keres(T* tomb, int db) {
	T minimum = tomb[0];
	for (int i = 1; i < db; i++) {
		if (tomb[i] < minimum) {
			minimum = tomb[i];
		}
	}
	return minimum;
}

int fv2(int a, int b = 1, int c = 2, int d = 3) {

}

int main() {
	fv2(1,1,2,9);

	cout << "hello" << endl;

	// vektor
	vektor3d v1;
	v1.x = 1;
	v1.y = 2;
	v1.z = 3;

	vektor3d v2;
	v2.x = 6;
	v2.y = 10;
	v2.z = 4;

	cout << "v1="; kiir(v1);
	cout << "v2="; kiir(v2);
	vektor3d v3 = v1+v2; // ugyanaz, mint: v3=operator+(v1,v2);
	cout << "v1+v2="; kiir(v3);

	// dátum
	datum ma;
	ma.ev = 2021;
	ma.ho = 2;
	ma.nap = 15;
	kiir(ma);

	// idõ
	ido most;
	most.ora = 14;
	most.perc = 53;
	kiir(most);

	// tömbben keresés
	int tomb[] = {1,2,3,3,1,2,-5,7};
	int* talalat = keres(tomb, 8, 2, 2);
	cout << "talalat helye 0x" << talalat << " cimen" << endl;
	cout << "talalat helye " << talalat-tomb << " indexen" << endl;
	cout << "legkisebb= " << minimum_keres(tomb, 8) << endl;

	// ref. gyakorlás
	int hany, mar;
	maradekos_osztas(14, 5, hany, mar);
	cout << "hanyados=" << hany << endl;
	cout << "maradek=" << mar << endl;

	// double típusú tömb kezelése sablon típussal
	double tomb2[] = { 1.2,2.6,3.123,3.12,1.8,2.13,5.123,7.74 };
	double* talalat2 = keres(tomb2, 8, 3.123, 2);
	cout << "legkisebb= " << minimum_keres(tomb2, 8) << endl;

	return 0;
}