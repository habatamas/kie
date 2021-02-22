#include <iostream>

using namespace std;

// marad�kosan oszt� f�ggv�ny
// be: osztand�, oszt�
// ki: h�nyados, marad�k
void maradekos_osztas(int osztando, int oszto, int &hanyados, int &maradek) {
	hanyados = osztando / oszto;
	maradek = osztando % oszto;
}

// b�rmilyen t�mbben keres�nk egy �rt�ket
// t�rjen vissza a tal�lat pointer�vel, vagy
// ha nincs tal�lat, akkor null pointerrel
template<typename T>
T* keres(T* t, int db, T keresett, int k=1) {
	int hanyadik = 0;
	for (int i = 0; i < db; i++) {
		// megtal�ltuk?
		if (t[i] == keresett) {
			// van tal�lat
			hanyadik++;

			// ez a tal�lat kellett?
			if (hanyadik == k) {
				return &(t[i]); // tal�lat pointere
			}
		}
	}

	// ha nincs tal�lat
	return nullptr; // C-ben: NULL
}

// d�tum
struct datum {
	int ev, ho, nap;
};

// d�tum ki�r�
void kiir(const datum &d) {
	cout << d.ev << "." << d.ho << "." << d.nap << endl;
}

// id�
struct ido {
	int ora, perc;
};

// id� ki�r�
void kiir(const ido& i) {
	cout << i.ora << ":" << i.perc << endl;
}

// hib�s fv. t�lterhel�s:
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

// sablon f�ggv�nyek
template<typename T1, typename T2>
void fv(T1 a, T2 b) {
	int c = (int)a;
}

// minimumkeres�s t�mbben
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

	// d�tum
	datum ma;
	ma.ev = 2021;
	ma.ho = 2;
	ma.nap = 15;
	kiir(ma);

	// id�
	ido most;
	most.ora = 14;
	most.perc = 53;
	kiir(most);

	// t�mbben keres�s
	int tomb[] = {1,2,3,3,1,2,-5,7};
	int* talalat = keres(tomb, 8, 2, 2);
	cout << "talalat helye 0x" << talalat << " cimen" << endl;
	cout << "talalat helye " << talalat-tomb << " indexen" << endl;
	cout << "legkisebb= " << minimum_keres(tomb, 8) << endl;

	// ref. gyakorl�s
	int hany, mar;
	maradekos_osztas(14, 5, hany, mar);
	cout << "hanyados=" << hany << endl;
	cout << "maradek=" << mar << endl;

	// double t�pus� t�mb kezel�se sablon t�pussal
	double tomb2[] = { 1.2,2.6,3.123,3.12,1.8,2.13,5.123,7.74 };
	double* talalat2 = keres(tomb2, 8, 3.123, 2);
	cout << "legkisebb= " << minimum_keres(tomb2, 8) << endl;

	return 0;
}