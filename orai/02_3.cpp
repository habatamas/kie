#include <iostream>

using namespace std;

class vektor3d {
private:
	double x, y, z;

public:
	void setX(int uj_x) {
		x = uj_x;
	}

	double getX() {
		return x;
	}

	void kiir() {
		cout << "[" << x;
		cout << " ; " << y;
		cout << " ; " << z << "]" << endl;
	}
};

int main() {
	cout << "hello" << endl;

	vektor3d v1;
	v1.setX(10);
	v1.kiir();

	cin.get();
	return 0;
}