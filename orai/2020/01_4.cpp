#include <iostream>

using namespace std;

void duplaz(int &szam) {
	szam *= 2;
}

void kiir(const int& szam) {
	cout << szam << endl;
}

struct ido {
	int ora, perc, masodperc;
};

void kiir_ido(const ido& i) {
	cout << i.ora << ':';
	cout << i.perc << ':';
	cout << i.masodperc << endl;
}

// elsõ n darab Fibonacci-szám
int* fib(int n) {
	int* szamok = new int[n]; // malloc(sizeof(int)*n)

	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1)
			szamok[i] = 1;
		else
			szamok[i] = szamok[i - 1] + szamok[i - 2];
	}

	return szamok;
}

int main() {
	cout << "hello MOGI" << endl;
	
	int a = 5;
	int& b = a; // referencia
	b = 6;
	cout << a << endl;
	cout << b << endl;
	
	duplaz(a);
	kiir(a);

	// dinamikus memóriakezelés
	int* t = fib(10);
	for (int i = 0; i < 10; i++)
		cout << t[i] << endl;
	delete[] t; // free(t)

	cin.get();
	return 0;
}