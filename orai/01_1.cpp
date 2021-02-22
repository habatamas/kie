#include <iostream> // ki- és bemenethez
#include <iomanip> // formázáshoz (setw, setfill stb.)
#include <cstdlib> // stdlib.h C-bõl
#include <ctime> // time.h C-bõl

using namespace std;

int main() {
	cout << "hello MOGI" << endl;

	// randomszámgenerálás
	srand(time(NULL));
	cout << rand() << endl;

	// tömbkezelés
	int *tomb = new int[10]; // ugyanaz, mint: tomb=(int*)malloc(10*sizeof(int));

	tomb[0] = 123;
	cout << tomb[0] << endl;

	delete[] tomb; // ugyanaz, mint: free(tomb);

	for (int i=1; i <= 10; i++) {
		cout << i << endl;
	}

	// beolvasás
	int szam;
	cout << "irj be egy szamot: ";
	cin >> szam;
	cout << "ezt irtad be: " << szam << endl;

	// adott szélességû mezõ
	cout << setfill('-');
	for (int i = 1; i <= 10; i++) {
		cout << setw(3) << i*i << endl;
	}

	// tizedesjegyek száma
	double tort = 1.23456789;
	cout << setprecision(5) << tort << endl;


	return 0;
}