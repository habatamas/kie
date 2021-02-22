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

	virtual void fv3() = 0; // a leszármazottnak kell megvalósítani
};

class Leszarmazott : public Ososztaly {
public:
	void fv() {
		vedett_adattag = 123; // védett adattagok elérhetõk
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
	ptr->fv(); // ilyenkor az õsosztály fv-e hívódik meg
	obj1.fv();

	ptr->fv2(); // ilyenkor a leszármazott fv2-je hívódik meg
	obj1.fv2();

	ptr->fv3();
	obj1.fv3();

	return 0;
}