#include <iostream>

using namespace std;

class Ososztaly {
protected:
	int adattag;
public:
	Ososztaly(int x) {
		adattag = x;
	}

	virtual void fuggveny1() {
		cout << "Ososztaly fuggveny1()" << endl;
	}

	virtual void fv() = 0;
};

class Leszarmazott : public Ososztaly {
public:
	Leszarmazott(int x) : Ososztaly(x) {
		// ...
	}

	void fv() {
		cout << "hello" << endl;
		adattag = 3;
	}

	void fuggveny1() {
		Ososztaly::fuggveny1();
		cout << "Leszarmazott fuggveny1()" << endl;
	}
};

void teszt(Ososztaly &r) {
	r.fuggveny1();
}

int main() {
	cout << "hello" << endl;

	Leszarmazott obj(3);
	obj.fuggveny1();

	Ososztaly *ptr;
	ptr = &obj;
	ptr->fuggveny1();

	cin.get();
	return 0;
}
