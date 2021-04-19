#include <iostream>

using namespace std;

class Osztaly {
public:
	int a;
	static int b;

	static void fv() {
		cout << "fv()" << endl;
		// ilyet nem lehet: a = 12;
		// ilyet sem: fv2();
	}

	void fv2() {
		fv(); // statikus fv hívás nem statikus kontextusból
	}
};
int Osztaly::b = 0;

int main() {
	// statikus tagváltozó elérése az osztályon keresztül
	Osztaly::b = 345;
	cout << "Osztaly::b==" << Osztaly::b << endl;

	// statikus tagfüggvény hívása az osztályon keresztül
	Osztaly::fv();

	// objektumok létrehozása (példányosítás)
	Osztaly obj1;
	Osztaly obj2;

	// statikus és "sima" tagváltozók elérése objektumon keresztül
	obj1.a = 12;
	obj1.b = 8;
	obj2.a = -100;
	obj2.b = 123;

	cout << "obj1.a==" << obj1.a << endl;
	cout << "obj2.a==" << obj2.a << endl;
	cout << "obj1.b==" << obj1.b << endl;
	cout << "obj2.b==" << obj2.b << endl;

	// statikus függvény meghívása objektumon keresztül
	obj1.fv();
	
	return 0;
}