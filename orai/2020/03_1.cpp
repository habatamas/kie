#include <iostream>
#include <cmath> // C-ben: math.h

using namespace std;

// komplex szám osztály
class complex {
private:
	// tagváltozók: valós és képzetes rész
	double re, im;

public:
	// konstruktor
	complex() {
		re = 0;
		im = 0;
		cout << "konstruktor meghivva" << endl;
	}

	complex(double re, double im) {
		this->re = re;
		this->im = im;
		cout << "masik konstruktor meghivva" << endl;
	}

	// másoló konstruktor
	complex(const complex &other) {
		re = other.re;
		im = other.im;
		cout << "masolas" << endl;
	}

	// setter függvények
	void setRe(double re) { this->re = re; }
	void setIm(double im) { this->im = im; }

	// getter függvények
	double getRe() const { return re; }
	double getIm() const { return im; }

	// trigonometrikus alak
	double getR() const {
		return sqrt(re * re + im * im);
	}

	double getTheta() const {
		return atan2(im, re);
	}

	void setR(double r) {
		double theta = getTheta();
		re = r * cos(theta);
		im = r * sin(theta);
	}

	void setTheta(double theta) {
		double r = getR();
		re = r * cos(theta);
		im = r * sin(theta);
	}

	// destruktor
	~complex() {
		cout << "destruktor meghivva" << endl;
	}
};

// http://users.hszk.bme.hu/~ht1520/ora.txt

void kiir(const complex &szam ) {
	cout << szam.getRe() << '+' << szam.getIm() << 'i' << endl;
}

complex *fg() {
	complex c(2, 3);
	kiir(c);

	complex* d = new complex(5, 6); // dinamikusan foglalt
	return d;
}

int main() {
	complex z4 = complex(2, 3); // egyenértékû: z4(2,3)

	complex *ptr = fg();
	ptr->setTheta(123);
	delete ptr;

	cout << ":)" << endl;

	complex z(3,4);
	kiir(z);
	cout << "r=" << z.getR() << endl;
	cout << "theta=" << z.getTheta() << endl;

	complex z2(9,8);
	kiir(z2);

	complex z3 = z2;
	kiir(z3);

	cin.get();
	return 0;
}