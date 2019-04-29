#include <iostream>

using namespace std;

template<typename T>
class Halmaz {
public:
	virtual bool bennevan(const T &elem) const = 0;
	virtual void betesz(const T &elem) = 0;
	virtual ~Halmaz() {
	}
};

template<typename T>
class TombHalmaz : public Halmaz<T> {
private:
	int meret; // tömb mérete
	T *elemek; // halmaz elemeinek tömbje

public:
	// üres halmaz létrehozása
	TombHalmaz() {
		meret = 0;
	}

	// tagság
	bool bennevan(const T &elem) const {
		for (int i = 0; i < meret; i++)
			if (elemek[i] == elem)
				return true;
		return false;
	}

	// elem betétele a halmazba
	void betesz(const T &elem) {
		// ha már szerepel, kész vagyunk
		if (bennevan(elem))
			return;

		// ha nem szerepel...
		// új tömb foglalása
		T *uj_elemek = new T[meret+1];

		// régi elemek átmásolása
		for (int i = 0; i < meret; i++)
			uj_elemek[i] = elemek[i];

		// új elem hozzáadása
		uj_elemek[meret] = elem;

		// régi tömb törlése
		delete[] elemek;

		// tagváltozók frissítése
		meret++;
		elemek = uj_elemek;
	}

	~TombHalmaz() {
		delete[] elemek;
	}

	// users.hszk.bme.hu/~ht1520/ora.txt
};

// elágazás a bináris fában
template<typename T>
struct Faag {
	T ertek;
	Faag<T> *kisebb;
	Faag<T> *nagyobb;
};

// bináris fa
template<typename T>
class BinarisFa : public Halmaz<T> {
private:
	Faag<T> *gyoker;

	void reszfa_torol(Faag<T> *reszfa) {
		// ha üres a részfa, nincs mit tenni
		if (reszfa == nullptr)
			return;

		// gyermek-részfák törlése
		reszfa_torol(reszfa->kisebb);
		reszfa_torol(reszfa->nagyobb);

		// adott elem törlése
		delete reszfa;
	}

public:
	// üres halmaz
	BinarisFa() {
		gyoker = nullptr;
	}

	// tagság vizsgálata
	bool bennevan(const T &elem) const {
		Faag<T> *aktualis = gyoker;

		while (aktualis != nullptr) {
			// megtaláltuk-e
			if (aktualis->ertek == elem)
				return true;

			// hova menjünk tovább?
			if (elem < aktualis->ertek)
				aktualis = aktualis->kisebb;
			else
				aktualis = aktualis->nagyobb;
		}

		return false;
	}

	// elem betétele a halmazba
	void betesz(const T &elem) {
		// ha már szerepelt, akkor kész vagyunk
		if (bennevan(elem))
			return;

		// új elem foglalása
		Faag<T> *uj_faag = new Faag<T>;
		uj_faag->ertek = elem;
		uj_faag->kisebb = nullptr;
		uj_faag->nagyobb = nullptr;

		// speciális eset: elsõ elem
		if (gyoker == nullptr) {
			gyoker = uj_faag;
			return;
		}

		// elindulunk a gyökértõl
		Faag<T> *aktualis = gyoker;

		while (true) {
			// merre lépjünk tovább?
			if (elem < aktualis->ertek) {
				// ha már nincs tovább, oda kerül az új elem
				if (aktualis->kisebb == nullptr) {
					aktualis->kisebb = uj_faag;
					return;
				}
				aktualis = aktualis->kisebb;
			} else {
				// ha már nincs tovább, oda kerül az új elem
				if (aktualis->nagyobb == nullptr) {
					aktualis->nagyobb = uj_faag;
					return;
				}
				aktualis = aktualis->nagyobb;
			}
		}
	}

	~BinarisFa() {
		reszfa_torol(gyoker);
	}
};

// halmaz tesztelése
void halmazTeszt( Halmaz<int> &h ) {
	cout << h.bennevan(0) << endl;
	cout << h.bennevan(1) << endl;
	cout << h.bennevan(2) << endl;

	h.betesz(0);
	h.betesz(1);
	h.betesz(2);

	cout << h.bennevan(0) << endl;
	cout << h.bennevan(1) << endl;
	cout << h.bennevan(2) << endl;
}

int main() {
	cout << "hello" << endl;

	BinarisFa<int> teszt_halmaz_1;
	halmazTeszt(teszt_halmaz_1);

	cin.get();
	return 0;
}