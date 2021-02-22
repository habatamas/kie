#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Komplex {
private:
	double im, re;
public:
	// ha nincs paraméter: 0
	Komplex() : im(0), re(0) {
	}

	// valós számból
	Komplex(double re) : im(0), re(re) {
	}

	// algebrai alakban
	Komplex(double re, double im) : im(im), re(re) {
	}

	// getterek
	double getRe() const { return re; }
	double getIm() const { return im; }

	// setterek
	void setRe(double re) { this->re = re; }
	void setIm(double im) { this->im = im; }

	Komplex operator+(const Komplex& masik) const {
		Komplex eredmeny;
		eredmeny.re = re + masik.re;
		eredmeny.im = im + masik.im;
		return eredmeny;
	}

	Komplex operator-(const Komplex & masik) const {
		Komplex eredmeny;
		eredmeny.re = re - masik.re;
		eredmeny.im = im - masik.im;
		return eredmeny;
	}

	Komplex operator*(const Komplex& masik) const {
		Komplex eredmeny;
		// (a+bi)*(c+di) = (a*c-b*d) + (a*d+b*c)i
		eredmeny.re = re * masik.re - im * masik.im;
		eredmeny.im = re * masik.im + im * masik.re;
		return eredmeny;
	}

	Komplex operator/(const Komplex& masik) const {
		// (a+bi)/(c+di) = (a+bi)*(c-di)/(c^2+d^2)
		double nevezo = masik.re * masik.re + masik.im * masik.im;
		Komplex konjugalt(masik.re, -masik.im);
		Komplex eredmeny = this->operator*(konjugalt); // !
		eredmeny.re /= nevezo;
		eredmeny.im /= nevezo;
		return eredmeny;
	}

	friend double abs(const Komplex& z) {
		return sqrt(pow(z.re, 2) + pow(z.im, 2));
	}

	void kiir() const {
		cout << re << "+" << im << "i" << endl;
	}

	friend ostream& operator<<(ostream &os, const Komplex &z) {
		os << z.re << "+" << z.im << "i" << endl;
		return os;
	}

	Komplex operator+=(const Komplex& masik) {
		re += masik.re;
		im += masik.im;
		return *this;
	}

	// -= *= /=

	// pre inkrementálás
	void operator++() {
		re++;
	}

	// poszt inkrementálás
	void operator++(int) {
		re++;
	}
};

int main() {

	int x=2;
	int y = x += 3;
	cout << x << endl;
	cout << y << endl;

	cout << ":)" << endl;

	Komplex z1(1, 2);
	Komplex z2(3, 4);
	Komplex z;
	z = z1 + z2;
	
	cout << "z1=" << z1 << endl;
	z1 += z2;
	cout << "z1=" << z1 << endl;
	z1++; // ez két külön 
	++z1; // mûvelet
	cout << "z1=" << z1 << endl;

	// z = z1.operator+(z2);
	
	(cout << z) << endl;

	cout << abs(z2) << endl;
	ofstream fki("komplex.txt");
	fki << z << endl;
	
	return 0;
}