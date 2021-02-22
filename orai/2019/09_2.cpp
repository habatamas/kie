#include <iostream>
#include <string>
#include <ostream>
#include <vector>

using namespace std;

template<typename Tipus>
struct Vektor3d {
	Tipus x, y, z;
};

template<typename KulcsTipus, typename ErtekTipus>
struct KulcsErtekPar {
	KulcsTipus kulcs;
	ErtekTipus ertek;

	friend ostream& operator<<(ostream &os, const KulcsErtekPar &par) {
		os << par.kulcs;
		os << " -> ";
		os << par.ertek;
		return os;
	}
};

// saját lista
template<typename T>
class Lista {
private:
	int meret; // lista elemszáma
	T *elemek; // lista elemeinek tömbje

public:
	Lista() {
		meret = 0;
	}

	Lista(const Lista<T> &eredeti) {
		meret = eredeti.meret;
		elemek = new T[meret];
		for (int i = 0; i < meret; i++)
			elemek[i] = eredeti[i];
	}

	void hozzafuz(const T &elem) {
		// új tömb létrehozása
		T *uj_elemek = new T[meret+1];

		// régi adatok átmásolása
		for (int i = 0; i < meret; i++)
			uj_elemek[i] = elemek[i];

		// régi adatok törlése
		if (meret != 0)
			delete[] elemek;

		// új elem beírása
		uj_elemek[meret] = elem;

		// átnevezések
		meret++;
		elemek = uj_elemek;
	}

	int getMeret() const {
		return meret;
	}

	T operator[](int index) const {
		return elemek[index];
	}

	friend ostream& operator<<(ostream &os, const Lista &l) {
		os << "{";
		for (int i = 0; i < l.getMeret() - 1; i++) {
			os << l[i] << ", ";
		}
		if (l.getMeret() != 0)
			os << l[l.getMeret() - 1];
		cout << "}";
		return os;
	}

	// listák összefûzése
	Lista<T> operator+(const Lista<T> &masik) const {
		Lista<T> eredmeny;

		for (int i = 0; i < meret; i++)
			eredmeny.hozzafuz(elemek[i]);
		for (int i = 0; i < masik.meret; i++)
			eredmeny.hozzafuz(masik[i]);

		return eredmeny;
	}

	~Lista() {
		if (meret != 0)
			delete[] elemek;
	}
};

// szótár adatszerkezet
template<typename KulcsTipus, typename ErtekTipus>
class Szotar {
private:
	int n; // elemszám
	KulcsTipus *kulcsok;
	ErtekTipus *ertekek;

public:
	Szotar() {
		n = 0;
	}

	// kulcs szerepel-e?
	bool kulcs_szerepel(const KulcsTipus &kulcs) {
		for (int i = 0; i < n; i++)
			if (kulcsok[i] == kulcs)
				return true;
		return false;
	}

	// kulcs-érték pár beírása
	void beir(const KulcsTipus &kulcs, const ErtekTipus &ertek) {
		// ha már szerepelt a kulcs, csak írja felül az értéket
		if (kulcs_szerepel(kulcs)) {
			for (int i = 0; i < n; i++) {
				if (kulcsok[i] == kulcs) {
					ertekek[i] = ertek;
					return;
				}
			}
		}

		// ha nem szerepelt a kulcs, akkor fûzzük hozzá
		// az új kulcs érték párt
		KulcsTipus *uj_kulcsok = new KulcsTipus[n + 1];
		ErtekTipus *uj_ertekek = new ErtekTipus[n + 1];

		// régi adatok átmásolása
		for (int i = 0; i < n; i++) {
			uj_kulcsok[i] = kulcsok[i];
			uj_ertekek[i] = ertekek[i];
		}

		// régi tömbök törlése
		delete[] kulcsok;
		delete[] ertekek;

		// új adat beírása
		uj_kulcsok[n] = kulcs;
		uj_ertekek[n] = ertek;

		// változók frissítése
		kulcsok = uj_kulcsok;
		ertekek = uj_ertekek;
		n++;
	}

	ErtekTipus operator[](const KulcsTipus &kulcs) {
		for (int i = 0; i < n; i++)
			if (kulcs == kulcsok[i])
				return ertekek[i];
	}
	// HF befejezni
};

int main() {
	Szotar<string, int> varosok;
	varosok.beir("Budapest", 2000000);
	varosok.beir("Szeged", 170000);

	cout << varosok["Budapest"] << endl;
	cout << varosok["Szeged"] << endl;

	Vektor3d<int> v1;

	v1.x = 3.1415;
	cout << v1.x << endl;

	KulcsErtekPar<string, int> a, b;
	a.kulcs = "Pisti"; a.ertek = 12;
	b.kulcs = "Kati"; b.ertek = 11;
	cout << a << endl << b << endl;

	// STL alapok
	vector<string> het_napjai;

	// adatok betevése
	het_napjai.push_back("hetfo");
	het_napjai.push_back("kedd");
	het_napjai.push_back("szerda");
	het_napjai.push_back("csutortok");
	het_napjai.push_back("pentek");
	het_napjai.push_back("szombat");
	het_napjai.push_back("hetfo");

	het_napjai[6] = "vasarnap";

	// elemek kiírása
	for (int i = 0; i < het_napjai.size(); i++) {
		cout << het_napjai[i] << endl;
	}

	// bejárás iterátorral
	cout << endl;
	for (vector<string>::iterator it = het_napjai.begin(); it != het_napjai.end(); it++) {
		cout << *it << endl;
	}

	// elem törlése
	for (int i = 0; i < het_napjai.size(); i++) {
		cout << het_napjai[i] << endl;
	}

	// saját lista
	Lista<string> napok;
	napok.hozzafuz("hetfo");
	napok.hozzafuz("kedd");
	napok.hozzafuz("szerda");

	napok[1] = "KEDD";

	cout << endl;
	for (int i = 0; i < napok.getMeret(); i++) {
		cout << napok[i] << endl;
	}

	cout << (napok+napok) << endl;
	cin.get();
	return 0;
}