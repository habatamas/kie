#include <iostream>

using namespace std;

class Osztaly {
private:
	static int adattag;
public:
	int masik_adattag;

	void set(int ertek) {
		adattag = ertek;
	}

	int get() const {
		return getAdattag();
	}

	static int getAdattag() {
		return adattag;
	}
};
int Osztaly::adattag;

class CsokiAutomata {
private:
	int* csoki_db; // melyik csokib�l h�ny db van
	int bedobott;
	int bevetel;

	static int osszbevetel;

public:
	CsokiAutomata(): bedobott(0), bevetel(0) {
		csoki_db = new int[100];
		for (int i = 0; i < 100; i++)
			csoki_db[i] = 10; // kezdetben minden csokib�l 10 db van
	}

	CsokiAutomata(const CsokiAutomata& eredeti) {
		csoki_db = new int[100];
		for (int i = 0; i < 100; i++)
			csoki_db[i] = eredeti.csoki_db[i];
		bedobott = eredeti.bedobott;
		bevetel = eredeti.bevetel;
		osszbevetel += bevetel;
	}

	// adott sorsz�m� csoki �ra
	int getAr(int sorszam) const {
		return sorszam + 100;
	}

	// adott csokib�l h�ny db �rhet� el
	int getDb(int sorszam) const {
		return csoki_db[sorszam];
	}

	void penzBedob(int penz) {
		bedobott += penz;
	}

	int getBedobott() const {
		return bedobott;
	}

	int vasarol(int sorszam) {
		// tudunk-e v�s�rolni?
		if (csoki_db[sorszam] == 0 || getAr(sorszam)>bedobott) {
			int bedobott_regi = bedobott;
			bedobott = 0;
			return bedobott_regi;
		}

		// ha tudunk v�s�rolni
		bevetel += getAr(sorszam);
		osszbevetel += getAr(sorszam);
		csoki_db[sorszam]--;
		int visszajaro = bedobott - getAr(sorszam);
		bedobott = 0;
		return visszajaro;
	}

	int getBevetel() const {
		return bevetel;
	}

	static int getOsszbevetel() {
		return osszbevetel;
	}

	~CsokiAutomata() {
		delete[] csoki_db;
	}
};
int CsokiAutomata::osszbevetel = 0;

int main() {

	CsokiAutomata a1;
	CsokiAutomata a2;

	a1.penzBedob(50);
	a1.penzBedob(100);
	cout << a1.getBedobott() << endl;
	cout << a1.getAr(0) << endl;
	cout << a1.getDb(0) << endl;
	cout << a1.vasarol(0) << endl;
	cout << a1.getDb(0) << endl;

	a2.penzBedob(1000);
	a2.vasarol(12);

	cout << a1.getBevetel() << endl;
	cout << a2.getBevetel() << endl;
	cout << CsokiAutomata::getOsszbevetel() << endl;

	return 0;
}