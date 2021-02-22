#include <iostream>
#include <string>
#include <cstdio> // stdio.h

using namespace std;

template<typename KulcsTipus, typename ErtekTipus>
class Szotar {
public:
	virtual void setElem(const KulcsTipus& kulcs, const ErtekTipus& ertek) = 0;
	virtual ErtekTipus getElem(const KulcsTipus& kulcs) const = 0;
	virtual void operator-=(const KulcsTipus& kulcs) = 0;
	virtual void kiir() const = 0;
	virtual ~Szotar() {	} /// !!!!
};

template<typename KulcsTipus, typename ErtekTipus>
class TombSzotar : public Szotar<KulcsTipus, ErtekTipus> {
private:
	int db; // hány kulcs-érték párt tárolunk
	KulcsTipus* kulcsok;
	ErtekTipus* ertekek;

public:
	TombSzotar() : db(0), kulcsok(nullptr), ertekek(nullptr) { }

	void setElem(const KulcsTipus& kulcs, const ErtekTipus& ertek) {
		// kulcs keresése
		for (int i = 0; i < db; i++) {
			if (kulcsok[i] == kulcs) {
				// van találat, írjuk felül az értéket
				ertekek[i] = ertek;
				// végeztünk
				return;
			}
		}

		// nincs találat, új kulcs-érték párt kell hozzáadni
		// új tömbök foglalása
		KulcsTipus* uj_kulcsok = new KulcsTipus[db + 1];
		ErtekTipus* uj_ertekek = new ErtekTipus[db + 1];
		// régi értékek átmásolása
		for (int i = 0; i < db; i++) {
			uj_kulcsok[i] = kulcsok[i];
			uj_ertekek[i] = ertekek[i];
		}
		// új kulcs-érték pár beírása
		uj_kulcsok[db] = kulcs;
		uj_ertekek[db] = ertek;
		// régi tömbök törlése
		delete[] kulcsok;
		delete[] ertekek;
		// változók frissítése
		kulcsok = uj_kulcsok;
		ertekek = uj_ertekek;
		db++;
	}

	ErtekTipus getElem(const KulcsTipus& kulcs) const {
		for (int i = 0; i < db; i++)
			if (kulcsok[i] == kulcs)
				return ertekek[i];
	}

	void operator-=(const KulcsTipus& kulcs) {
		for (int i = 0; i < db; i++) {
			if (kulcsok[i] == kulcs) {
				// van találat, elemet kell törölni
				KulcsTipus* uj_kulcsok = new KulcsTipus[db - 1];
				ErtekTipus* uj_ertekek = new ErtekTipus[db - 1];
				// a szükséges elemek átmásolása
				for (int j = 0; j < db - 1; j++) {
					// ha a törlendõ elem elõtt vagyunk
					if (j < i) {
						uj_kulcsok[j] = kulcsok[j];
						uj_ertekek[j] = ertekek[j];
					} else { // ha a törlendõ elem után vagyunk
						uj_kulcsok[j] = kulcsok[j + 1];
						uj_ertekek[j] = ertekek[j + 1];
					}
				}
				// régi tömbök törlése
				delete[] kulcsok;
				delete[] ertekek;
				// változók frissítése
				kulcsok = uj_kulcsok;
				ertekek = uj_ertekek;
				db--;
				return;
			}
		}
	}

	void kiir() const {
		for (int i = 0; i < db; i++) {
			cout << kulcsok[i] << '\t' << ertekek[i] << endl;
		}
	}

	~TombSzotar() {
		// takarítás
		delete[] kulcsok;
		delete[] ertekek;
	}
};

int main() {
	TombSzotar<string, string> emberek;

	bool kilep = false;
	while (!kilep) {
		// menü megjelenítése
		cout << "______________________________" << endl;
		cout << "1: uj ember" << endl;
		cout << "2: nev lekeres" << endl;
		cout << "3: nev modositas" << endl;
		cout << "4: ember torles" << endl;
		cout << "5: osszes listazasa" << endl;
		cout << "6: kilepes" << endl;

		// választás bekérése
		int valasztas;
		cout << "valassz menupontot: ";
		cin >> valasztas;

		// menüpontok kezelése
		string taj;
		string nev;
		switch (valasztas)
		{
		case 1: // fallthrough
		case 3: 
			cout << "TAJ szam: ";
			cin >> taj;
			cout << "nev: ";
			do {
				getline(cin, nev);
			} while (nev == "");
			emberek.setElem(taj, nev);
			break;
		case 2:
			cout << "TAJ szam: ";
			cin >> taj;
			cout << emberek.getElem(taj) << endl;
			break;
		case 4:
			cout << "TAJ szam: ";
			cin >> taj;
			emberek -= taj;
			break;
		case 5:
			emberek.kiir();
			break;
		case 6: // kilépés
			kilep = true;
			break;
		default:
			break;
		}
	}

	return 0;
}