#include <iostream> // ki- �s bemenethez
#include <iomanip> // form�z�shoz (setw, setfill stb.)
#include <cstdlib> // stdlib.h C-b�l
#include <ctime> // time.h C-b�l

using namespace std;

int main() {
	cout << "hello MOGI" << endl;

	// randomsz�mgener�l�s
	srand(time(NULL));
	cout << rand() << endl;

	// t�mbkezel�s
	int *tomb = new int[10]; // ugyanaz, mint: tomb=(int*)malloc(10*sizeof(int));

	tomb[0] = 123;
	cout << tomb[0] << endl;

	delete[] tomb; // ugyanaz, mint: free(tomb);

	for (int i=1; i <= 10; i++) {
		cout << i << endl;
	}

	// beolvas�s
	int szam;
	cout << "irj be egy szamot: ";
	cin >> szam;
	cout << "ezt irtad be: " << szam << endl;

	// adott sz�less�g� mez�
	cout << setfill('-');
	for (int i = 1; i <= 10; i++) {
		cout << setw(3) << i*i << endl;
	}

	// tizedesjegyek sz�ma
	double tort = 1.23456789;
	cout << setprecision(5) << tort << endl;


	return 0;
}