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
	int db; // h�ny kulcs-�rt�k p�rt t�rolunk
	KulcsTipus* kulcsok;
	ErtekTipus* ertekek;

public:
	TombSzotar() : db(0), kulcsok(nullptr), ertekek(nullptr) { }

	void setElem(const KulcsTipus& kulcs, const ErtekTipus& ertek) {
		// kulcs keres�se
		for (int i = 0; i < db; i++) {
			if (kulcsok[i] == kulcs) {
				// van tal�lat, �rjuk fel�l az �rt�ket
				ertekek[i] = ertek;
				// v�gezt�nk
				return;
			}
		}

		// nincs tal�lat, �j kulcs-�rt�k p�rt kell hozz�adni
		// �j t�mb�k foglal�sa
		KulcsTipus* uj_kulcsok = new KulcsTipus[db + 1];
		ErtekTipus* uj_ertekek = new ErtekTipus[db + 1];
		// r�gi �rt�kek �tm�sol�sa
		for (int i = 0; i < db; i++) {
			uj_kulcsok[i] = kulcsok[i];
			uj_ertekek[i] = ertekek[i];
		}
		// �j kulcs-�rt�k p�r be�r�sa
		uj_kulcsok[db] = kulcs;
		uj_ertekek[db] = ertek;
		// r�gi t�mb�k t�rl�se
		delete[] kulcsok;
		delete[] ertekek;
		// v�ltoz�k friss�t�se
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
				// van tal�lat, elemet kell t�r�lni
				KulcsTipus* uj_kulcsok = new KulcsTipus[db - 1];
				ErtekTipus* uj_ertekek = new ErtekTipus[db - 1];
				// a sz�ks�ges elemek �tm�sol�sa
				for (int j = 0; j < db - 1; j++) {
					// ha a t�rlend� elem el�tt vagyunk
					if (j < i) {
						uj_kulcsok[j] = kulcsok[j];
						uj_ertekek[j] = ertekek[j];
					} else { // ha a t�rlend� elem ut�n vagyunk
						uj_kulcsok[j] = kulcsok[j + 1];
						uj_ertekek[j] = ertekek[j + 1];
					}
				}
				// r�gi t�mb�k t�rl�se
				delete[] kulcsok;
				delete[] ertekek;
				// v�ltoz�k friss�t�se
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
		// takar�t�s
		delete[] kulcsok;
		delete[] ertekek;
	}
};

int main() {
	TombSzotar<string, string> emberek;

	bool kilep = false;
	while (!kilep) {
		// men� megjelen�t�se
		cout << "______________________________" << endl;
		cout << "1: uj ember" << endl;
		cout << "2: nev lekeres" << endl;
		cout << "3: nev modositas" << endl;
		cout << "4: ember torles" << endl;
		cout << "5: osszes listazasa" << endl;
		cout << "6: kilepes" << endl;

		// v�laszt�s bek�r�se
		int valasztas;
		cout << "valassz menupontot: ";
		cin >> valasztas;

		// men�pontok kezel�se
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
		case 6: // kil�p�s
			kilep = true;
			break;
		default:
			break;
		}
	}

	return 0;
}