#include <iostream>

using namespace std;

template<typename T>
class Halmaz {
public:
	virtual bool bennevan(const T& elem) const = 0;
	virtual void betesz(const T& elem) = 0;
	virtual ~Halmaz() {

	}
};

// tömbhalmaz
template<typename T>
class TombHalmaz : public Halmaz<T> {
private:
	int db;
	T* elemek;
public:
	TombHalmaz() : db(0), elemek(nullptr) {
	}

	bool bennevan(const T& elem) const {
		for (int i = 0; i < db; i++)
			if (elemek[i] == elem)
				return true;
		return false;
	}

	void betesz(const T& elem) {
		if (bennevan(elem))
			return;

		T* uj_elemek = new T[db + 1];
		for (int i = 0; i < db; i++)
			uj_elemek[i] = elemek[i];
		uj_elemek[db] = elem;
		delete[] elemek;
		elemek = uj_elemek;
		db++;
	}

	~TombHalmaz() {
		delete[] elemek;
	}
};

template<typename T>
struct Elagazas {
	T adat;
	Elagazas<T>* kisebb, * nagyobb;
};


template<typename T>
class BinarisFa : public Halmaz<T> {
private:
	Elagazas<T>* gyoker;

	// rekurzió!
	void reszfa_torol(Elagazas<T> *reszfa) {
		// fa végére értünk, akkor nincs dolgunk.
		if (reszfa == nullptr)
			return;

		// innen kiinduló részfák törlése
		reszfa_torol(reszfa->kisebb);
		reszfa_torol(reszfa->nagyobb);
		delete reszfa; // aktuális elágazás törlése
	}

public:
	BinarisFa() : gyoker(nullptr) {
	}


	virtual bool bennevan(const T& elem) const {
		Elagazas<T>* aktualis = gyoker;
		while (aktualis != nullptr) {
			// épp a keresett elemen vagyunk
			if (aktualis->adat == elem)
				return true;

			// merre menjünk tovább?
			if (aktualis->adat > elem)
				aktualis = aktualis->kisebb;
			else
				aktualis = aktualis->nagyobb;
		}
		return false;
	}

	virtual void betesz(const T& elem) {
		// új elágazás
		Elagazas<T>* uj_elagazas = new Elagazas<T>;
		uj_elagazas->adat = elem;
		uj_elagazas->kisebb = nullptr;
		uj_elagazas->nagyobb = nullptr;

		// spec. eset: legelsõ elem
		if (gyoker == nullptr) {
			gyoker = uj_elagazas;
			return;
		}

		// sima eset: sokadik elem
		Elagazas<T>* aktualis = gyoker;

		while (aktualis != nullptr) {
			// nem lehet egy elem többször a halmazban
			if (aktualis->adat == elem) {
				delete uj_elagazas;
				return;
			}
			if (aktualis->adat > elem) {
				if (aktualis->kisebb == nullptr) {
					aktualis->kisebb = uj_elagazas;
					return;
				}
				aktualis = aktualis->kisebb;
			} else {
				if (aktualis->nagyobb == nullptr) {
					aktualis->nagyobb = uj_elagazas;
					return;
				}
				aktualis = aktualis->nagyobb;
			}
		}
	}

	virtual ~BinarisFa() {
		reszfa_torol(gyoker);
	}
};

int main() {
	cout << "hello" << endl;

	BinarisFa<int> h;
	h.betesz(2);
	h.betesz(2020);
	h.betesz(6);

	for (int i = 0; i < 10; i++) {
		cout << "irj be egy szamot: ";
		int szam;
		cin >> szam;
		cout << h.bennevan(szam) << endl;
	}



	return 0;
}

