#ifndef __VEKTOR_H // include guard
#define __VEKTOR_H

#include <iostream>

using namespace std;

// "matematikai" vektor
class vektor {
private:
	int dim; // hány dimenziós?
	double* elemek; // a vektor elemei

public:

	// konstruktor függvény

	// n-dimenziós nullvektor
	vektor(int n);

	// copy konstruktor
	vektor(const vektor& eredeti);

	// setter és getter függvény: privát tagváltozók lekérdezése és beállítása

	// dimenzió lekérése
	int getDim() const;

	// vektor i-edik elemének lekérése
	double getElem(int i) const;

	// vektor i-edik elemének beállítása
	void setElem(int i, double ertek);

	// vektor kiírása
	void kiir() const;

	vektor operator+(const vektor& masik);

	// destruktor
	~vektor();
};

#endif