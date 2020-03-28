#include <iostream>

using namespace std;

class vektor3d {
private:
	double x, y, z;
	
public:
	void set_x(double uj_x) { x = uj_x; }
	void set_y(double uj_y) { y = uj_y; }
	void set_z(double uj_z) { z = uj_z; }

	void kiir() const {
		cout << x << ";";
		cout << y << ";";
		cout << z << endl;
	}
};

void f(const vektor3d& v) {
	v.kiir();
}

int main() {
	vektor3d v1;
	v1.set_x(100);
	v1.set_x(2);
	v1.set_x(-5);
	v1.kiir();

	cout << "hello " << endl;
	cin.get();
	return 0;
}