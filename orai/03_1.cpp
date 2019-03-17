#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

class vektor3d {
private:
	double x, y, z;

public:
	// alapértelmezett konstruktor
	vektor3d() {
		cout << "vektor letrejott" << endl;
		x = 0;
		y = 0;
		z = 0;
	}

	vektor3d(double uj_x, double uj_y, double uj_z) {
		x = uj_x;
		y = uj_y;
		z = uj_z;
	}

	// publikus setterek és getterek
	// a privát tagváltozók eléréséhez
	void setX(double uj_x) { x = uj_x; }
	
	double getX() const {
		return x;
	}

	void setY(double uj_y) { y = uj_y; }

	double getY() const {
		return y;
	}

	void setZ(double uj_z) { z = uj_z; }

	double getZ() const {
		return z;
	}

	double getHossz() const {
		return sqrt(x*x + y*y + z*z);
	}


};

void kiir(const vektor3d &v) {
	cout << "[" << v.getX();
	cout << "   " << v.getY();
	cout << "   " << v.getZ() << "]" << endl;
}

vektor3d *i_bazis() {
	vektor3d *p = new vektor3d(1,0,0);
	return p;
}

class vektorND {
private:
	double *koordinatak; // tömb
	int dim; // dimenziók száma

public:
	// n dimenziós nullvektor létrehozása
	vektorND(int dim) {
		this->dim = dim;
		koordinatak = new double[dim];

		for (int i = 0; i < dim; i++)
			koordinatak[i] = 0;
	}

	// 3d vektor létrehozása
	vektorND(double x, double y, double z) {
		dim = 3;
		koordinatak = new double[3];
		koordinatak[0] = x;
		koordinatak[1] = y;
		koordinatak[2] = z;
	}
	
	// copy konstruktor
	vektorND(const vektorND &eredeti) {
		dim = eredeti.dim;
		koordinatak = new double[dim];

		for (int i = 0; i < dim; i++)
			koordinatak[i] = eredeti.koordinatak[i];
	}

	// koordináta setter getter
	double getKoord(int i) const {
		return koordinatak[i];
	}

	void setKoord(int i, double koord) {
		koordinatak[i] = koord;
	}

	// dimenzió getter
	int getDim() const {
		return dim;
	}

	void setDim(int dim) {
		// új tömb foglalása
		double *uj_koordinatak = new double[dim];

		// értékek átmásolása
		for (int i = 0; i < dim; i++) {
			if (i < this->dim) {
				uj_koordinatak[i] = koordinatak[i];
			} else {
				uj_koordinatak[i] = 0;
			}
		}

		// régi tömb törlése
		delete[] koordinatak;

		// tagváltozók frissítése
		this->dim = dim;
		koordinatak = uj_koordinatak;
	}

	// vektor hossza
	double getHossz() const {
		double negyzetosszeg = 0;
		for (int i = 0; i < dim; i++)
			negyzetosszeg += koordinatak[i] * koordinatak[i];
		return sqrt(negyzetosszeg);
	}

	// skaláris szorzat
	double szorzat(const vektorND &masik) const {
		double sum=0;

		for (int i = 0; i < dim && i < masik.dim; i++)
			sum += koordinatak[i] * masik.koordinatak[i];

		return sum;
	}

	// normalizáló
	void normalizal() {
		double hossz = getHossz();
		for (int i = 0; i < dim; i++)
			koordinatak[i] /= hossz;
	}

	// destruktor
	~vektorND() {
		delete[] koordinatak;
	}
};

void kiir(const vektorND &v) {
	cout << "[";
	for (int i = 0; i < v.getDim(); i++) {
		cout << setw(10) << v.getKoord(i);
	}
	cout << "]" << endl;
}

int main() {
	vektorND v5d(5);
	v5d.setKoord(0, 10);
	v5d.setKoord(1, 20);
	v5d.setKoord(2, 3000);
	v5d.setKoord(3, 40);
	v5d.setKoord(4, 3.141592);
	kiir(v5d);
	v5d.setDim(3);
	kiir(v5d);
	cout << "hossz: " << v5d.getHossz() << endl;
	v5d.normalizal();
	kiir(v5d);
	cout << "hossz: " << v5d.getHossz() << endl;

	cout << "hello" << endl;

	// copy teszt
	vektorND masolat = v5d;
	v5d.setKoord(0, 0);
	kiir(masolat);

	// variációk példányosításra
	vektor3d v1; // alapértelmezett
	vektor3d v2 = vektor3d(4, 5, 6); // másik konstruktor
	vektor3d v3(7,8,9); // másik írásmód

	// dinamikus memóriakezelés
	vektor3d *pv;
	pv = new vektor3d(1,3,4);

	pv->setX(1000);

	(*pv).setY(999);

	kiir(*pv);

	delete pv;

	vektor3d *i = i_bazis();
	kiir(*i);
	delete i;

	// kiíró függvény
	kiir(v1);
	kiir(v2);
	kiir(v3);
	
	// tagfüggvények használata
	v1.setX(1);
	v1.setY(2);
	v1.setZ(3);

	kiir(v1);
	
	cout << "hossz: " << v1.getHossz() << endl;


	cin.get();
	return 0;
}