#include <iostream>

using namespace std;

void fuggveny(const int &x) {
	cout << x << endl;
	cout << &x << endl;
}

int main() {
	cout << "hello" << endl;

	int a = 2;
	cout << a << endl; // a értéke
	cout << &a << endl; // a memóriacíme
	fuggveny(a); // ?

	cin.get();
	return 0;
}