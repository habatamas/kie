#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// f�jlba �r�s
	ofstream fki;
	fki.open("teszt.txt",ios_base::app);

	cout << "jo reggelt" << endl;

	fki << "valami szoveg" << endl;
	fki << "valami masik szoveg" << endl;

	// f�jlb�l olvas�s
	ifstream fbe("teszt.txt");
	
	string valami;
	getline(fbe, valami,'\t');
	cout << "beolvasott: " << valami << endl;

	getline(fbe, valami);
	cout << "beolvasott: " << valami << endl;

	int a, b;
	fbe >> a; fbe >> b;
	cout << a << " " << b << endl;

	return 0;
}