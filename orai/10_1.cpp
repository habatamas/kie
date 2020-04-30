#include <iostream>

using namespace std;

class Ososztaly {
private:
	int privat_adattag;
protected:
	int vedett_adattag;
public:
	void fv() {
		cout << "Ososztaly objektuma vagyok." << endl;
	}

	virtual void fv2() {
		cout << "Ososztaly objektuma vagyok." << endl;
	}

	virtual void fv3() = 0; // a lesz�rmazottnak kell megval�s�tani
};

class Leszarmazott : public Ososztaly {
public:
	void fv() {
		vedett_adattag = 123; // v�dett adattagok el�rhet�k
		cout << "A leszarmazott osztaly objektuma vagyok" << endl;
	}

	void fv2() {
		cout << "A leszarmazott osztaly objektuma vagyok" << endl;
	}

	void fv3() {
		cout << "fv3() implementacio" << endl;
	}
};

int main() {
	cout << "hello" << endl;
	Leszarmazott obj1;
	Ososztaly* ptr = &obj1;
	ptr->fv(); // ilyenkor az �soszt�ly fv-e h�v�dik meg
	obj1.fv();

	ptr->fv2(); // ilyenkor a lesz�rmazott fv2-je h�v�dik meg
	obj1.fv2();

	ptr->fv3();
	obj1.fv3();

	return 0;
}