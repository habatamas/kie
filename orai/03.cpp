#include <iostream>
#include <cmath>
#include "vektor.h"

using namespace std;

double hossz(vektor v) {
	return sqrt(v.getElem(0) * v.getElem(0) +
		        v.getElem(1) * v.getElem(1) +
		        v.getElem(2) * v.getElem(2));
}

int main() {
	// példányosítás lokális változóval
	vektor v1 = vektor(3);
	cout << v1.getDim() << endl;
	v1.setElem(0, 5);
	v1.setElem(1, 7);
	v1.setElem(2, -3);
	cout << "v1=";
	v1.kiir();
	cout << "|v1|=" << hossz(v1) << endl;

	vektor masolat = v1;
	cout << "masolat=";
	masolat.kiir();

	// alternatív szintaxis
	vektor v2(3); // kompakt forma
	v2.setElem(1, 123);

	vektor sum = v1 + v2;
	// ezt is írhattam volna:
  //vektor sum = v1.operator+(v2);
	sum.kiir();

	// példányosítás new operátorral
	vektor* v3 = new vektor(3);
	cout << v3->getDim() << endl;

	delete v3;

	return 0;
}