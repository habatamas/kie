#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

class vektor3d {
private:
	double x, y, z;

public:
	// alap�rtelmezett konstruktor
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

	// publikus setterek �s getterek
	// a priv�t tagv�ltoz�k el�r�s�hez
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
	double *koordinatak; // t�mb
	int dim; // dimenzi�k sz�ma

public:
	// n dimenzi�s nullvektor l�trehoz�sa
	vektorND(int dim) {
		this->dim = dim;
		koordinatak = new double[dim];

		for (int i = 0; i < dim; i++)
			koordinatak[i] = 0;
	}

	// 3d vektor l�trehoz�sa
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

	// koordin�ta setter getter
	double getKoord(int i) const {
		return koordinatak[i];
	}

	void setKoord(int i, double koord) {
		koordinatak[i] = koord;
	}

	// dimenzi� getter
	int getDim() const {
		return dim;
	}

	void setDim(int dim) {
		// �j t�mb foglal�sa
		double *uj_koordinatak = new double[dim];

		// �rt�kek �tm�sol�sa
		for (int i = 0; i < dim; i++) {
			if (i < this->dim) {
				uj_koordinatak[i] = koordinatak[i];
			} else {
				uj_koordinatak[i] = 0;
			}
		}

		// r�gi t�mb t�rl�se
		delete[] koordinatak;

		// tagv�ltoz�k friss�t�se
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

	// skal�ris szorzat
	double szorzat(const vektorND &masik) const {
		double sum=0;

		for (int i = 0; i < dim && i < masik.dim; i++)
			sum += koordinatak[i] * masik.koordinatak[i];

		return sum;
	}

	// normaliz�l�
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

	// vari�ci�k p�ld�nyos�t�sra
	vektor3d v1; // alap�rtelmezett
	vektor3d v2 = vektor3d(4, 5, 6); // m�sik konstruktor
	vektor3d v3(7,8,9); // m�sik �r�sm�d

	// dinamikus mem�riakezel�s
	vektor3d *pv;
	pv = new vektor3d(1,3,4);

	pv->setX(1000);

	(*pv).setY(999);

	kiir(*pv);

	delete pv;

	vektor3d *i = i_bazis();
	kiir(*i);
	delete i;

	// ki�r� f�ggv�ny
	kiir(v1);
	kiir(v2);
	kiir(v3);
	
	// tagf�ggv�nyek haszn�lata
	v1.setX(1);
	v1.setY(2);
	v1.setZ(3);

	kiir(v1);
	
	cout << "hossz: " << v1.getHossz() << endl;


	cin.get();
	return 0;
}