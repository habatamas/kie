#include "vektor.h"

// n-dimenziós nullvektor
vektor::vektor(int n) {
	cout << "konstruktor meghivva" << endl;
	dim = n;
	elemek = new double[dim];
	for (int i = 0; i < n; i++)
		elemek[i] = 0;
}

// copy konstruktor
vektor::vektor(const vektor& eredeti) {
	dim = eredeti.dim;
	elemek = new double[dim]; /// saját területet kell foglalni!
	for (int i = 0; i < dim; i++)
		elemek[i] = eredeti.elemek[i];
}

// setter és getter függvény: privát tagváltozók lekérdezése és beállítása

// dimenzió lekérése
int vektor::getDim() const {
	return dim;
}

// vektor i-edik elemének lekérése
double vektor::getElem(int i) const {
	return elemek[i];
}

// vektor i-edik elemének beállítása
void vektor::setElem(int i, double ertek) {
	if (i < dim)
		elemek[i] = ertek;
}

// vektor kiírása
void vektor::kiir() const {
	cout << "[";
	for (int i = 0; i < dim; i++)
		cout << elemek[i] << ", ";
	cout << "]" << endl;
}

// + operátor
vektor vektor::operator+(const vektor& masik) {
	vektor osszeg(dim);
	for (int i = 0; i < dim; i++) {
		osszeg.elemek[i] = elemek[i] + masik.elemek[i];
	}
	return osszeg;
}

// destruktor
vektor::~vektor() {
	cout << "destruktor meghivva" << endl;
	delete[] elemek;
}