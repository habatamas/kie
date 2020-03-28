#include <iostream>
#include <cmath>

using namespace std;

class vektor {
private:
	int dim;
	double* elemek;

public:
	// n dimenziós nullvektor létrehozása
	vektor(int dim) {
		this->dim = dim;
		elemek = new double[dim];
		for (int i = 0; i < dim; i++)
			elemek[i] = 0;
	}

	// copy konstruktor
	vektor(const vektor& eredeti) {
		dim = eredeti.dim;
		elemek = new double[dim];
		for (int i = 0; i < dim; i++)
			elemek[i] = eredeti.elemek[i];
	}

	// getterek
	double getHossz() const {
		double negyzetosszeg = 0;
		for (int i = 0; i < dim; i++)
			negyzetosszeg += elemek[i] * elemek[i];
		return sqrt(negyzetosszeg);
	}
	// http://users.hszk.bme.hu/~ht1520/ora.txt

	int getDim() const {
		return dim;
	}
	double getElem(int index) const {
		return elemek[index];
	}

	// setterek
	void setElem(int index, double ertek) {
		elemek[index] = ertek;
	}

	// kiírás
	void kiir() const {
		cout << "[";
		for (int i = 0; i < dim; i++) {
			cout << elemek[i];
			if (i != dim - 1) // ha nem az utolsó elem
				cout << ", ";
		}
		cout << "]" << endl;
	}

	vektor operator+(const vektor &masik) const {
		vektor eredmeny = *this;
		for (int i = 0; i < dim; i++)
			eredmeny.elemek[i] += masik.elemek[i];
		return eredmeny;
	}

	// destruktor
	~vektor() {
		delete[] elemek;
	}
};

int main() {
	vektor v(5);
	vektor v2 = v;
	
	v.setElem(3, 3.141592);
	v.kiir();

	v2.kiir();
	vektor v3 = v + v2;
	vektor v4 = v.operator+(v2); // elõzõvel ekvivalens
	v3.kiir();


	cout << "hello MOGI" << endl;
	

	
	cin.get();
	return 0;
}