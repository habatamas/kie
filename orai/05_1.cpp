#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// csv �rtelmez� oszt�ly
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
				// megvan a megfelel� tal�lat
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
	// melyik f�jlt nyissa meg?
	CSVparser(const string &fajlnev, const string &elv=",") {
		bemenet = new ifstream(fajlnev);
		this->elv = elv;
	}

	// �res-e a f�jl?
	bool ures() const {
		return bemenet->eof();
	}

	// sor beolvas�sa
	void beolvas() {
		getline(*bemenet, sor);
	}

	// oszlopok sz�ma
	int oszlopok_szama() const {
		int honnan = 0;
		int n = 1;
		while (sor.find(elv, honnan) != -1) {
			honnan = sor.find(elv, honnan) + elv.length();
			n++;
		}
		return n;
	}

	// adott mez� lek�r�se
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
	// f�jlban csere
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


	// cser�l�
	string s = "123:(asdasd:(abcd:(";
	csere(s, ":(", ":)");
	cout << s;

	CSVparser parser("adatok.csv", ";");

	// �sszbev�tel sz�mol�sa
	int sum = 0;

	// melyik napon volt a legnagyobb bev�tel �s az mennyi?
	string max_nap;
	int max_bevetel;
	bool elso = true;

	while (!parser.ures()) {
		// egy sor beolvas
		parser.beolvas();

		if (parser.oszlopok_szama() == 2 && parser.mezo_leker(0)!="") {
			// sorb�l adatok kinyer�se
			string nap = parser.mezo_leker(0);
			int bevetel = stoi(parser.mezo_leker(1));

			// max bev�tel
			if (elso || bevetel > max_bevetel) {
				max_bevetel = bevetel;
				max_nap = nap;
				elso = false;
			}

			// �sszbev�tel sz�m�t�sa
			sum += bevetel;
		}
	}

	cout << "osszbevetel: " << sum << endl;
	cout << "max: " << max_nap << "$: " << max_bevetel << endl;

	cin.get();
	return 0;
}
