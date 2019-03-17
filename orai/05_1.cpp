#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// csv értelmezõ osztály
class CSVparser {
private:
	ifstream *bemenet;
	string sor;
	string elv;

	string keres(const string &miben, const string &mit, int i) const {
		int honnan = 0;
		int hanyadik = 0;
		while ( true ) {
			if (hanyadik == i) {
				// megvan a megfelelõ találat
				int meddig = miben.find(mit, honnan);
				if (meddig == -1) {
					return miben.substr(honnan);
				} else {
					return miben.substr(honnan, meddig - honnan);
				}
			}
			honnan = miben.find(mit, honnan) + mit.length();
			hanyadik++;
		}
	}

public:
	// melyik fájlt nyissa meg?
	CSVparser(const string &fajlnev, const string &elv=",") {
		bemenet = new ifstream(fajlnev);
		this->elv = elv;
	}

	// üres-e a fájl?
	bool ures() const {
		return bemenet->eof();
	}

	// sor beolvasása
	void beolvas() {
		getline(*bemenet, sor);
	}

	// oszlopok száma
	int oszlopok_szama() const {
		int honnan = 0;
		int n = 1;
		while (sor.find(elv, honnan) != -1) {
			honnan = sor.find(elv, honnan) + elv.length();
			n++;
		}
		return n;
	}

	// adott mezõ lekérése
	string mezo_leker(int index) {
		return keres(sor, elv, index);
	}

	// destruktor
	~CSVparser() {
		delete bemenet;
	}
};

void csere(string &miben, const string &mit, const string &mire) {
	while (miben.find(mit) != -1) {
		int talalat = miben.find(mit);
		miben = miben.substr(0, talalat)
			    + mire
			    + miben.substr(talalat+mit.length());
	}
}

int main() {
	// fájlban csere
	string bemeneti_fajlnev = "adatok.csv";
	string kimeneti_fajlnev = "masik.txt";

	ifstream csere_be(bemeneti_fajlnev);
	ofstream csere_ki(kimeneti_fajlnev);

	string mit = ";", mire = ",";

	while (!csere_be.eof()) {
		string sor;
		getline(csere_be, sor);
		csere(sor, mit, mire);
		csere_ki << sor << endl;
	}


	// cserélõ
	string s = "123:(asdasd:(abcd:(";
	csere(s, ":(", ":)");
	cout << s;

	CSVparser parser("adatok.csv", ";");

	// összbevétel számolása
	int sum = 0;

	// melyik napon volt a legnagyobb bevétel és az mennyi?
	string max_nap;
	int max_bevetel;
	bool elso = true;

	while (!parser.ures()) {
		// egy sor beolvas
		parser.beolvas();

		if (parser.oszlopok_szama() == 2 && parser.mezo_leker(0)!="") {
			// sorból adatok kinyerése
			string nap = parser.mezo_leker(0);
			int bevetel = stoi(parser.mezo_leker(1));

			// max bevétel
			if (elso || bevetel > max_bevetel) {
				max_bevetel = bevetel;
				max_nap = nap;
				elso = false;
			}

			// összbevétel számítása
			sum += bevetel;
		}
	}

	cout << "osszbevetel: " << sum << endl;
	cout << "max: " << max_nap << "$: " << max_bevetel << endl;

	cin.get();
	return 0;
}
