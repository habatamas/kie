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
		fv(); // statikus fv h�v�s nem statikus kontextusb�l
	}
};
int Osztaly::b = 0;

int main() {
	// statikus tagv�ltoz� el�r�se az oszt�lyon kereszt�l
	Osztaly::b = 345;
	cout << "Osztaly::b==" << Osztaly::b << endl;

	// statikus tagf�ggv�ny h�v�sa az oszt�lyon kereszt�l
	Osztaly::fv();

	// objektumok l�trehoz�sa (p�ld�nyos�t�s)
	Osztaly obj1;
	Osztaly obj2;

	// statikus �s "sima" tagv�ltoz�k el�r�se objektumon kereszt�l
	obj1.a = 12;
	obj1.b = 8;
	obj2.a = -100;
	obj2.b = 123;

	cout << "obj1.a==" << obj1.a << endl;
	cout << "obj2.a==" << obj2.a << endl;
	cout << "obj1.b==" << obj1.b << endl;
	cout << "obj2.b==" << obj2.b << endl;

	// statikus f�ggv�ny megh�v�sa objektumon kereszt�l
	obj1.fv();
	
	return 0;
}