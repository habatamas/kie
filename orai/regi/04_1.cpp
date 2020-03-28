#include <iostream>

using namespace std;

class Osztaly {
public:
	Osztaly() {
		cout << "a)" << endl;
	}

	Osztaly(const Osztaly &o) {
		cout << "b)" << endl;
	}

	~Osztaly() {
		cout << "c)" << endl;
	}
};

Osztaly *fv() {
	Osztaly *p = new Osztaly;
	Osztaly valami;
	return p;
}

int main() {
	cout << "hello" << endl;

	Osztaly a;
	Osztaly b=a;
	new Osztaly;
	delete fv();

	cin.get();
	return 0;
}