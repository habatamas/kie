#include "vektor.h"

// n-dimenzi�s nullvektor
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
	elemek = new double[dim]; /// saj�t ter�letet kell foglalni!
	for (int i = 0; i < dim; i++)
		elemek[i] = eredeti.elemek[i];
}

// setter �s getter f�ggv�ny: priv�t tagv�ltoz�k lek�rdez�se �s be�ll�t�sa

// dimenzi� lek�r�se
int vektor::getDim() const {
	return dim;
}

// vektor i-edik elem�nek lek�r�se
double vektor::getElem(int i) const {
	return elemek[i];
}

// vektor i-edik elem�nek be�ll�t�sa
void vektor::setElem(int i, double ertek) {
	if (i < dim)
		elemek[i] = ertek;
}

// vektor ki�r�sa
void vektor::kiir() const {
	cout << "[";
	for (int i = 0; i < dim; i++)
		cout << elemek[i] << ", ";
	cout << "]" << endl;
}

// + oper�tor
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