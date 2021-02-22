#include <iostream>

using namespace std;

class Kimutatas {
private:
	int beszamolasi_ido;
	int* bevetelek;
	int honap;

	static int teljes_bevetel;

public:
	Kimutatas(int beszamolasi_ido): beszamolasi_ido(beszamolasi_ido), honap(0) {
		bevetelek = new int[beszamolasi_ido];
	}

	Kimutatas(const Kimutatas& eredeti) {
		beszamolasi_ido = eredeti.beszamolasi_ido;
		honap = eredeti.honap;
		bevetelek = new int[beszamolasi_ido];
		for (int i = 0; i < beszamolasi_ido; i++)
			bevetelek[i] = eredeti.bevetelek[i];
		
	}

	void bevetelRogzit(int bevetel) {
		if (honap == beszamolasi_ido)
			honap = 0;

		teljes_bevetel += bevetel;
		bevetelek[honap] = bevetel;
		honap++;
	}

	int getOsszbevetel() const {
		int osszeg = 0;
		for (int i = 0; i < beszamolasi_ido; i++)
			osszeg += bevetelek[i];
		return osszeg;
	}

	double getAtlag() const {
		return (double)getOsszbevetel() / beszamolasi_ido;
	}

	int getMinimum() const {
		int legkisebb = bevetelek[0];
		for (int i = 0; i < beszamolasi_ido; i++)
			if (bevetelek[i] < legkisebb)
				legkisebb = bevetelek[i];
		return legkisebb;
	}

	int getMaximum() const {
		int legnagyobb = bevetelek[0];
		for (int i = 0; i < beszamolasi_ido; i++)
			if (bevetelek[i] > legnagyobb)
				legnagyobb = bevetelek[i];
		return legnagyobb;
	}

	int getMedian() {
		// rendezzük a tömböt
		for(int i = 0; i < beszamolasi_ido; i++) {
			for (int j = 0; j < beszamolasi_ido - 1; j++) {
				if (bevetelek[j] > bevetelek[j + 1]) {
					int tmp = bevetelek[j];
					bevetelek[j] = bevetelek[j + 1];
					bevetelek[j + 1] = tmp;
				}
			}
		}

		// középsõ elem
		if (beszamolasi_ido % 2 == 0) {
			return (bevetelek[beszamolasi_ido/2] + bevetelek[beszamolasi_ido / 2-1])/ 2.0;
		}
		return bevetelek[beszamolasi_ido / 2];
	}

	static int getTeljesBevetel() {
		return teljes_bevetel;
	}

	~Kimutatas() {
		delete[] bevetelek;
	}
};
int Kimutatas::teljes_bevetel = 0;

int main() {
	cout << "hello world" << endl;

	Kimutatas k1(3);
	k1.bevetelRogzit(5);
	k1.bevetelRogzit(6);

	Kimutatas masolat(k1);

	k1.bevetelRogzit(4);

	cout << k1.getAtlag() << endl;
	cout << k1.getMinimum() << endl;
	cout << k1.getMaximum() << endl;

	k1.bevetelRogzit(50);
	k1.bevetelRogzit(60);
	k1.bevetelRogzit(40);

	cout << k1.getAtlag() << endl;
	cout << k1.getMinimum() << endl;
	cout << k1.getMaximum() << endl;

	Kimutatas k2(5);
	k2.bevetelRogzit(3);
	k2.bevetelRogzit(123);
	k2.bevetelRogzit(754);
	k2.bevetelRogzit(1);
	k2.bevetelRogzit(21);
	cout << k2.getMedian() << endl;

	cout << Kimutatas::getTeljesBevetel() << endl;

	masolat.bevetelRogzit(99);
	cout << masolat.getAtlag() << endl;

	return 0;
}