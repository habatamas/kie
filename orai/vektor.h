#ifndef __VEKTOR_H // include guard
#define __VEKTOR_H

#include <iostream>

using namespace std;

// "matematikai" vektor
class vektor {
private:
	int dim; // h�ny dimenzi�s?
	double* elemek; // a vektor elemei

public:

	// konstruktor f�ggv�ny

	// n-dimenzi�s nullvektor
	vektor(int n);

	// copy konstruktor
	vektor(const vektor& eredeti);

	// setter �s getter f�ggv�ny: priv�t tagv�ltoz�k lek�rdez�se �s be�ll�t�sa

	// dimenzi� lek�r�se
	int getDim() const;

	// vektor i-edik elem�nek lek�r�se
	double getElem(int i) const;

	// vektor i-edik elem�nek be�ll�t�sa
	void setElem(int i, double ertek);

	// vektor ki�r�sa
	void kiir() const;

	vektor operator+(const vektor& masik);

	// destruktor
	~vektor();
};

#endif