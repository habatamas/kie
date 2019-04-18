#include <iostream>
#include <ostream>

using namespace std;

class Idopont {
private:
	int ora, perc, masodperc;

public:
	Idopont(int ora, int perc, int masodperc) :
		ora(ora), perc(perc), masodperc(masodperc) { }

	// ez nem tagfüggvény!!!!
	friend ostream& operator<<(ostream &os, const Idopont &i) {
		os << i.ora << ":" << i.perc << ":" << i.masodperc;
		return os;
	}

	// ++ operátor: egy másodpercet adunk hozzá
	Idopont& operator++() {
		masodperc++;
		if (masodperc == 60) {
			masodperc = 0;
			perc++;
		}
		if (perc == 60) {
			perc = 0;
			ora++;
		}
		return *this;
	}

	// ++ operátor (poszt)
	Idopont operator++(int x) {
		Idopont elozo = *this;

		masodperc++;
		if (masodperc == 60) {
			masodperc = 0;
			perc++;
		}
		if (perc == 60) {
			perc = 0;
			ora++;
		}

		return elozo;
	}
};

int main() {
	cout << "hello" << endl;
	
	Idopont most(8, 20, 6);
	cout << most << ":)" << endl;
	cout << most++ << endl;
	cout << ++(++most) << endl;

	cin.get();
}