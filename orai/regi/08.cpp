#include <iostream>
#include <iomanip>
#include <ostream>

using namespace std;

class Vector2d {
private:
	double x, y;
public:
	// nullvektor létrehozása
	Vector2d(): x(0), y(0) { }

	// tetszőleges vektor létrehozása
	Vector2d(double x, double y) : x(x), y(y) {	}

	// setterek, getterek
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }

	// + operátor
	Vector2d operator+(const Vector2d &masik) const {
		Vector2d eredmeny;
		eredmeny.x = x + masik.x;
		eredmeny.y = y + masik.y;
		return eredmeny;
	}

	// - operátor
	Vector2d operator-(const Vector2d &masik) const {
		Vector2d eredmeny;
		eredmeny.x = x - masik.x;
		eredmeny.y = y - masik.y;
		return eredmeny;
	}

	// * skalárral szorzás
	Vector2d operator*(double tenyezo) const {
		Vector2d eredmeny;
		eredmeny.x = x * tenyezo;
		eredmeny.y = y * tenyezo;
		return eredmeny;
	}

	// * skaláris szorzat
	double operator*(const Vector2d &masik) {
		return x * masik.x + y * masik.y;
	}

	friend Vector2d operator*(double a, const Vector2d &b);

	bool operator==(const Vector2d &masik) const {
		return (x == masik.x) && (y == masik.y);
	}
};

struct Datum {
	int ev, honap, nap;

	Datum(): ev(0), honap(0), nap(0) {
	}

	Datum(int ev, int honap, int nap) :
		ev(ev), honap(honap), nap(nap) {
	}

	bool operator==(const Datum &masik) const {
		return (ev == masik.ev) &&
			   (honap == masik.honap) &&
			   (nap == masik.nap);
	}

	bool operator<(const Datum &masik) const {
		if (ev != masik.ev)
			return ev < masik.ev;
		if (honap != masik.honap)
			return honap < masik.honap;
		return nap < masik.nap;
	}

	// következő nap (pre inkrementálás)
	Datum& operator++() {
		nap++;
		if (nap == 31) {
			nap = 1;
			honap++;
		}
		if (honap == 13) {
			honap = 1;
			ev++;
		}
		return *this;
	}

	// post increment
	Datum operator++(int) {
		// elmentjük a korábbi állapotot
		Datum korabbi(ev,honap,nap); 

		// megváltozatjuk az állapotot
		nap++;
		if (nap == 31) {
			nap = 1;
			honap++;
		}
		if (honap == 13) {
			honap = 1;
			ev++;
		}

		// a korábbi állapottal térünk vissza
		return korabbi;
	}
};

// barátfüggvény
Vector2d operator*(double a, const Vector2d &b) {
	Vector2d eredmeny;
	eredmeny.x = a * b.x;
	eredmeny.y = a * b.y;
	return eredmeny;
}

void kiir(const Vector2d &v) {
	cout << "[";
	cout << setw(10) << v.getX();
	cout << ";" << setw(10) << v.getY() << "]" << endl;
}

ostream& operator<<(ostream &os, const Datum &d) {
	os << d.ev << ".";
	os << setfill('0') << setw(2) << d.honap;
	os << "." << setw(2) << d.nap << ".";
	os << setfill(' ');
	return os;
}

void kiir(const Datum &d) {
	cout << d.ev << ".";
	cout << setfill('0') << setw(2) << d.honap;
	cout << "." << setw(2) << d.nap << "." << endl;
	cout << setfill(' ');
}

int main() {
	int x = 0;
	cout << ++(++x) << x << endl;


	Datum datumok[5] = {Datum(2016,4,8),
						Datum(2016,12,12),
						Datum(2011,12,12),
						Datum(2019,04,04),
						Datum(2001,5,9) };

	cout << "rendezetlen:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << datumok[i] << endl;
	}

	for (int meddig = 3; meddig >= 0; meddig--) {
		for (int i = 0; i <= meddig; i++) {
			// ha rossz a sorrend
			if (datumok[i + 1] < datumok[i]) {
				// akkor csere
				Datum tmp = datumok[i];
				datumok[i] = datumok[i + 1];
				datumok[i + 1] = tmp;
			}
		}
	}

	cout << "rendezett:" << endl;
	for (int i = 0; i < 5; i++) {
		kiir(datumok[i]);
	}
	cout << endl << endl;

	kiir(Datum(2019, 1, 2));
	cout << "hello" << endl;
	Vector2d nullvektor, valami(1, 2);
	kiir(nullvektor);
	kiir(valami);

	Vector2d v1(3, 4), v2(6,7);
	kiir(v1 + v2);
	kiir(v1.operator+(v2));
	
	Vector2d kulonbseg = v1 - v2;
	kiir(kulonbseg);

	cout << v1*v2 << endl;
	kiir(v1 * 10);
	kiir(10*v1);

	// dátumlépegetés
	Datum ma(2019, 4, 4);
	while (ma < Datum(2019, 5, 5)) {
		kiir((++ma)++);
	}

	cin.get();
	return 0;
}
