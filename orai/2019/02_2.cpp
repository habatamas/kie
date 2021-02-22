#include <iostream>

using namespace std;

int *szamlalo(int meddig, int hanyasaval=1) {
	// tömb foglalása
	int *tomb = new int[meddig/hanyasaval];

	// tömb feltöltése
	int j = 1;
	for (int i = 0; i < meddig / hanyasaval; i++) {
		tomb[i] = j;
		j += hanyasaval;
	}

	// visszatérés a tömbbel
	return tomb;
}

template<typename Tipus, typename T2>
int keres(Tipus *tomb, int db, T2 keresett, int hanyadik=0) {
	for (int i = 0; i < db; i++) {
		if (tomb[i] == keresett) {
			// ha ez az a találat, amelyik kell
			if (hanyadik == 0)
				return i;
			// ha nem, akkor még várunk
			hanyadik--;
		}
	}

	return -1;
}

struct vektor3d {
	double x, y, z;
};

// vektor kiírása
void kiir(const vektor3d &v) {
	cout << "[" << v.x << " ; ";
	cout        << v.y << " ; ";
	cout        << v.z << "]"   << endl;
}

// vektor és skalár szorzata
vektor3d operator*(const vektor3d &v, double a) {
	vektor3d eredmeny;
	eredmeny.x = v.x * a;
	eredmeny.y = v.y * a;
	eredmeny.z = v.z * a;
	return eredmeny;
}

// skaláris szorzat
double operator*(const vektor3d &v1, const vektor3d &v2) {
	double szorzat = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	return szorzat;
}

// minimumkeresés
template<typename T>
T minimumkereso(T *tomb, int db) {
	T minimum = tomb[0];
	for (int i = 1; i < db; i++)
		if (tomb[i] < minimum)
			minimum = tomb[i];
	return minimum;
}

int main() {
	cout << "hello" << endl;

	cout << "tizig egyesevel:" << endl;
	int *tizig = szamlalo(10);
	for (int i = 0; i < 10; i++)
		cout << tizig[i] << endl;
	delete[] tizig;


	cout << "tizig kettesevel:" << endl;
	int *tizig2 = szamlalo(10, 2);
	for (int i = 0; i < 5; i++)
		cout << tizig2[i] << endl;
	delete[] tizig2;

	// keresõ függvény teszt
	int t1[] = {2,3,5,8,234,123,41,1,2};
	cout << "talalat:" << keres(t1, 9, 2, 1) << endl;
	cout << "minimum: " << minimumkereso(t1, 9) << endl;

	double t2[] = { 2,3,5,8,234,123,41,1,2 };
	cout << "talalat:" << keres(t2, 9, 123) << endl;
	cout << "minimum: " << minimumkereso(t2, 9) << endl;

	// vektor
	vektor3d v1;
	v1.x = 1;
	v1.y = 2;
	v1.z = 3;
	kiir(v1);
	vektor3d v2 = v1 * 10;
	kiir(v2);

	cout << v1 * v2 << endl;

	cin.get();
	return 0;
}