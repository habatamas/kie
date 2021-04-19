#include <iostream>
#include <cmath>

using namespace std;

class Komplex {
private:
	double im, re;
public:
	// nulla
	Komplex() {
		im = 0;
		re = 0;
	}

	// valós szám
	Komplex(double ertek) {
		im = 0;
		re = ertek;
	}

	// algebrai alakban megadás
	Komplex(double re, double im) {
		this->re = re;
		this->im = im;
	}

	// copy konstruktor
	Komplex(const Komplex& eredeti) {
		re = eredeti.re;
		im = eredeti.im;
	}

	// trigonometrikus alak
	static Komplex fromTrig(double r, double theta) {
		Komplex z;
		z.re = r * cos(theta);
		z.im = r * sin(theta);
		return z;
	}

	// kiíró
	void kiir() const {
		cout << re << "+" << im << "*i" << endl;
	}

	// + operátor
	Komplex operator+(const Komplex& masik) const {
		Komplex z(re+masik.re, im+masik.im);
		return z;
	}

	// kivonás
	Komplex operator-(const Komplex& masik) const {
		Komplex z(re - masik.re, im - masik.im);
		return z;
	}
	
	// szorzás
	Komplex operator*(const Komplex& masik) {
		Komplex z;
		z.re = re * masik.re - im * masik.im;
		z.im = re * masik.im + masik.re * im;
		return z;
	}

	// konjugált
	Komplex operator~() const {
		Komplex z(re,-im);
		return z;
	}

	// osztás
	Komplex operator/(const Komplex& masik) {
		// (a+bi)/(c+di) = (a+bi)*(c-di)/((c+di)*(c-di)) =
		// (a + bi) * (c - di) / (c^2 + d^2)
		Komplex z = (*this) * (~masik); // (a + bi) * (c - di)
		z.re /= pow(masik.re, 2) + pow(masik.im,2);
		z.im /= pow(masik.re, 2) + pow(masik.im,2);
		return z;
	}

	friend ostream& operator<<(ostream& os, const Komplex& z) {
		os << z.re << "+" << z.im << "*i";
		return os;
	}
};



int main() {
	Komplex z1(3, 4);
	z1.kiir();
	Komplex z2 = Komplex::fromTrig(sqrt(2), 3.141592/4);
	z2.kiir();

	Komplex z3 = z1 + z2;
	z3.kiir();

	Komplex z4 = z1.operator+(z2); // teljesen ugyanazs

	(z1 * z2).kiir();
	(z1 * z2 / z2).kiir();

	((cout << "z1=") << z1) << endl;

	cout << z1; // ez
	operator<<(cout, z1); // és ez ekvivalens

	return 0;
}