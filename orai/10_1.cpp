#include <iostream>
#include <cmath>

using namespace std;

class Alakzat {
protected:
	double x, y;
public:
	Alakzat(double x, double y) : x(x), y(y) {
	}

	double getX() const { return x; };
	double getY() const { return y; };
	void kiir_poz() const {
		cout << "x=" << x << ", y=" << y << endl;
	}
	void athelyez(double x, double y) {
		this->x = x;
		this->y = y;
	}

	virtual void tipus_kiir() const { // virtu�lis f�ggv�ny
		cout << "Alakzat" << endl;
	}

	virtual double terulet() const = 0; // tiszt�n virtu�lis f�ggv�ny
};

class Teglalap : public Alakzat {
private:
	double w, h; // sz�less�g, magass�g

public:
	Teglalap(double x, double  y, double w, double h): Alakzat(x,y) ,w(w), h(h){
	}
	double getW() const { return w; };
	double getH() const { return h; };
	double terulet() const {
		return w * h;
	}

	void tipus_kiir() const {
		cout << "Teglalap" << endl;
	}
};

class Kor : public Alakzat {
private:
	double r; // sug�r

public:
	Kor(double x, double y, double r) : Alakzat(x,y), r(r) {
	}

	double getR() const { return r; };

	double terulet() const {
		return r * r * acos(-1); // (most nem tal�ltam az M_PI makr�t)
	}

	void tipus_kiir() const {
		cout << "Kor" << endl;
	}
};

int main() {
	Kor k1(2, 3, 10);
	k1.kiir_poz();
	k1.athelyez(0, -1);
	cout << endl << "terulet: " << k1.terulet() << endl;
	k1.tipus_kiir();

	Alakzat& alakzat = k1;
	alakzat.kiir_poz();
	cout << endl << "terulet: " << alakzat.terulet() << endl;
	alakzat.tipus_kiir();
	

	return 0;
}