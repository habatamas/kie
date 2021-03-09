#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// mozgóátlag osztály
// fertõzések száma
// tagfüggvények: új napi adat felvétele, utolsó 7 nap átlaga
class Mozgoatlag {
private:
	int* adatok;
	int n;

public:
	Mozgoatlag(int n){
		this->n = n;

		// terület foglalása
		adatok = new int[n];

		// adatok inicializálása
		for (int i = 0; i < n; i++)
			adatok[i] = 0;
	}

	void regisztral(int uj) {
		for (int i = n-1; i > 0; i--) {
			adatok[i] = adatok[i - 1];
		}
		adatok[0] = uj;
	}

	double atlag() const {
		double sum = 0;
		for (int i = 0; i < n; i++)
			sum += adatok[i];
		return sum / n;
	}

	Mozgoatlag(const Mozgoatlag &eredeti) {
		n = eredeti.n;
		adatok = new int[n];
		for (int i = 0; i < n; i++)
			adatok[i] = eredeti.adatok[i];
	}

	~Mozgoatlag() {
		delete[] adatok;
	}
};

int main() {
	srand(time(NULL));

	Mozgoatlag atl(7);

	for (int i = 0; i < 100; i++) {
		int uj = i * i + rand() % 10 - 5;
		atl.regisztral(uj);
		cout << uj << "\t" << atl.atlag() << endl;
	}

	return 0;
}