#include <iostream>

using namespace std;

// alapértelmezett argumentumok
double* intervallum(double tol, double ig, double lepes=1) {
	int n = (ig - tol) / lepes;
	double* tomb = new double[n];

	for (int i = 0; i < n; i++) {
		tomb[i] = tol + lepes * i;
	}

	return tomb;
}

// keres függvény: visszatér a keresett elem indexével,
// vagy -1-et ad, ha nem találja
template <typename Tipus>
int keres(Tipus* szamok, int meret, Tipus keresett, int hanyadik=0) {
	for (int i = 0; i < meret; i++) {
		if (szamok[i] == keresett) {
			if(hanyadik==0)
				return i;
			hanyadik--;
		}
	}
	return -1;
}

// sablon függvények
template <typename Tipus>
void kiir(Tipus *t, int n) {
	cout << "a tomb elemei: ";
	for (int i = 0; i < n; i++)
		cout << t[i] << ", ";
	cout << endl;
}

// maximumkeresés
template <typename T>
T maximumkeres(T* tomb, int n) {
	T max = tomb[0];
	for (int i = 0; i < n; i++)
		if (tomb[i] > max)
			max = tomb[i];
	return max;
}

struct pont3d {
	double x, y, z;
};

void kiir(const pont3d &p) {
	cout << "Pont(";
	cout << p.x << ";";
	cout << p.y << ";";
	cout << p.z << ")" << endl;
}

// operátor túlterhelés
pont3d operator+(const pont3d& p1, const pont3d& p2) {
	pont3d osszeg = {p1.x+p2.x,
		             p1.y+p2.y,
	                 p1.z+p2.z};
	return osszeg;
}

pont3d operator*=(pont3d &p, double s) {
	p.x *= s;
	p.y *= s;
	p.z *= s;
	return p;
}

int main() {
	pont3d P = { 5,-3.14,99 };
	pont3d Q = { 4,1,2 };
	kiir(P);
	kiir(P + Q);
	Q *= 100;
	kiir(Q);

	// 
	int szam = 3;
	cout << "???: " << (szam *= 4) << endl;

	int t[] = {1,2,4,5,6,1,2,3,5,2,1};
	kiir(t, 11);
	cout << "talalat:" << keres(t, 11, 5, 2) << endl;
	cout << "max: " << maximumkeres(t, 11) << endl;

	double* szamok = intervallum(1, 10,0.5);
	for (int i = 0; i < 18; i++) {
		cout << szamok[i] << endl;
	}
	cout << "max: " << maximumkeres(szamok, 18) << endl;
	delete[] szamok;

	cin.get();
	return 0;
}