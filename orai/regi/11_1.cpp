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
	int meret; // t�mb m�rete
	T *elemek; // halmaz elemeinek t�mbje

public:
	// �res halmaz l�trehoz�sa
	TombHalmaz() {
		meret = 0;
	}

	// tags�g
	bool bennevan(const T &elem) const {
		for (int i = 0; i < meret; i++)
			if (elemek[i] == elem)
				return true;
		return false;
	}

	// elem bet�tele a halmazba
	void betesz(const T &elem) {
		// ha m�r szerepel, k�sz vagyunk
		if (bennevan(elem))
			return;

		// ha nem szerepel...
		// �j t�mb foglal�sa
		T *uj_elemek = new T[meret+1];

		// r�gi elemek �tm�sol�sa
		for (int i = 0; i < meret; i++)
			uj_elemek[i] = elemek[i];

		// �j elem hozz�ad�sa
		uj_elemek[meret] = elem;

		// r�gi t�mb t�rl�se
		delete[] elemek;

		// tagv�ltoz�k friss�t�se
		meret++;
		elemek = uj_elemek;
	}

	~TombHalmaz() {
		delete[] elemek;
	}

	// users.hszk.bme.hu/~ht1520/ora.txt
};

// el�gaz�s a bin�ris f�ban
template<typename T>
struct Faag {
	T ertek;
	Faag<T> *kisebb;
	Faag<T> *nagyobb;
};

// bin�ris fa
template<typename T>
class BinarisFa : public Halmaz<T> {
private:
	Faag<T> *gyoker;

	void reszfa_torol(Faag<T> *reszfa) {
		// ha �res a r�szfa, nincs mit tenni
		if (reszfa == nullptr)
			return;

		// gyermek-r�szf�k t�rl�se
		reszfa_torol(reszfa->kisebb);
		reszfa_torol(reszfa->nagyobb);

		// adott elem t�rl�se
		delete reszfa;
	}

public:
	// �res halmaz
	BinarisFa() {
		gyoker = nullptr;
	}

	// tags�g vizsg�lata
	bool bennevan(const T &elem) const {
		Faag<T> *aktualis = gyoker;

		while (aktualis != nullptr) {
			// megtal�ltuk-e
			if (aktualis->ertek == elem)
				return true;

			// hova menj�nk tov�bb?
			if (elem < aktualis->ertek)
				aktualis = aktualis->kisebb;
			else
				aktualis = aktualis->nagyobb;
		}

		return false;
	}

	// elem bet�tele a halmazba
	void betesz(const T &elem) {
		// ha m�r szerepelt, akkor k�sz vagyunk
		if (bennevan(elem))
			return;

		// �j elem foglal�sa
		Faag<T> *uj_faag = new Faag<T>;
		uj_faag->ertek = elem;
		uj_faag->kisebb = nullptr;
		uj_faag->nagyobb = nullptr;

		// speci�lis eset: els� elem
		if (gyoker == nullptr) {
			gyoker = uj_faag;
			return;
		}

		// elindulunk a gy�k�rt�l
		Faag<T> *aktualis = gyoker;

		while (true) {
			// merre l�pj�nk tov�bb?
			if (elem < aktualis->ertek) {
				// ha m�r nincs tov�bb, oda ker�l az �j elem
				if (aktualis->kisebb == nullptr) {
					aktualis->kisebb = uj_faag;
					return;
				}
				aktualis = aktualis->kisebb;
			} else {
				// ha m�r nincs tov�bb, oda ker�l az �j elem
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

// halmaz tesztel�se
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