#include <iostream>

using namespace std;

void maradekos_osztas(int osztando, int oszto,
	                  int& hanyados, int& maradek) {
	hanyados = osztando / oszto;
	maradek  = osztando % oszto;
}

// referencia szerinti param�ter�tad�s
void duplaz(int &szam) {
	szam *= 2;
}

// konstans referencia (p�lda)
void kiir(const int &szam) {
	cout << "az atadott szam: " << szam << endl;
}

struct ido {
	int ora, perc, masodperc;
};

// itt hasznos a konstans referencia, hisz
// nem kell feleslegesen m�solgatni
void kiir_ido(const ido& i) {
	cout << i.ora << ':' << i.perc << ':' << i.masodperc << endl;
}

// els� n db Fibonacci-sz�m
int* fib(int n) {
	int* szamok = new int[n];
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1)
			szamok[i] = 1;
		else
			szamok[i] = szamok[i - 1] + szamok[i - 2];
	}
	return szamok;
}


int main() {
	cout << "hello mogi" << endl;

	int a = 3;
	duplaz(a);
	kiir(a);

	
	// fib
	int db;
	cout << "hany Fibonacci-szam kell? ";
	cin >> db;
	int* fib_szamok = fib(db);
	for (int i = 0; i < db; i++) {
		cout << fib_szamok[i] << endl;
	}
	delete[] fib_szamok;

	// 10 int-b�l �ll� t�mb
	int* t = new int[10];
	
	// ...

	// felszabad�t�s
	delete[] t;

	int h, m;
	maradekos_osztas(78,5,h,m);
	cout << h << "," << m << endl;

	cin.get();

	return 0;
}