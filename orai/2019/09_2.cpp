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

// saj�t lista
template<typename T>
class Lista {
private:
	int meret; // lista elemsz�ma
	T *elemek; // lista elemeinek t�mbje

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
		// �j t�mb l�trehoz�sa
		T *uj_elemek = new T[meret+1];

		// r�gi adatok �tm�sol�sa
		for (int i = 0; i < meret; i++)
			uj_elemek[i] = elemek[i];

		// r�gi adatok t�rl�se
		if (meret != 0)
			delete[] elemek;

		// �j elem be�r�sa
		uj_elemek[meret] = elem;

		// �tnevez�sek
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

	// list�k �sszef�z�se
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

// sz�t�r adatszerkezet
template<typename KulcsTipus, typename ErtekTipus>
class Szotar {
private:
	int n; // elemsz�m
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

	// kulcs-�rt�k p�r be�r�sa
	void beir(const KulcsTipus &kulcs, const ErtekTipus &ertek) {
		// ha m�r szerepelt a kulcs, csak �rja fel�l az �rt�ket
		if (kulcs_szerepel(kulcs)) {
			for (int i = 0; i < n; i++) {
				if (kulcsok[i] == kulcs) {
					ertekek[i] = ertek;
					return;
				}
			}
		}

		// ha nem szerepelt a kulcs, akkor f�zz�k hozz�
		// az �j kulcs �rt�k p�rt
		KulcsTipus *uj_kulcsok = new KulcsTipus[n + 1];
		ErtekTipus *uj_ertekek = new ErtekTipus[n + 1];

		// r�gi adatok �tm�sol�sa
		for (int i = 0; i < n; i++) {
			uj_kulcsok[i] = kulcsok[i];
			uj_ertekek[i] = ertekek[i];
		}

		// r�gi t�mb�k t�rl�se
		delete[] kulcsok;
		delete[] ertekek;

		// �j adat be�r�sa
		uj_kulcsok[n] = kulcs;
		uj_ertekek[n] = ertek;

		// v�ltoz�k friss�t�se
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

	// adatok betev�se
	het_napjai.push_back("hetfo");
	het_napjai.push_back("kedd");
	het_napjai.push_back("szerda");
	het_napjai.push_back("csutortok");
	het_napjai.push_back("pentek");
	het_napjai.push_back("szombat");
	het_napjai.push_back("hetfo");

	het_napjai[6] = "vasarnap";

	// elemek ki�r�sa
	for (int i = 0; i < het_napjai.size(); i++) {
		cout << het_napjai[i] << endl;
	}

	// bej�r�s iter�torral
	cout << endl;
	for (vector<string>::iterator it = het_napjai.begin(); it != het_napjai.end(); it++) {
		cout << *it << endl;
	}

	// elem t�rl�se
	for (int i = 0; i < het_napjai.size(); i++) {
		cout << het_napjai[i] << endl;
	}

	// saj�t lista
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