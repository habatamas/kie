#include <iostream>
#include <string>

using namespace std;

/*
Lista adatszerkezet
- több, ugyanolyan (de tetszõleges) típusú elemet tartalmaz
- a sorrendjük lényeges
- az elemekre indexekkel hivatkozunk (lekérjük, felülírjuk)
- új elem hozzáfûzése a lista végére
- elemek száma lekérhetõ
*/
template<typename T>
class Lista {
public:
	virtual T getElem(int index) const = 0;
	virtual void setElem(int index, const T& ertek) = 0;
	virtual void hozzafuz(const T& uj_elem) = 0;
	virtual int getDb() const = 0;



	virtual ~Lista() {
	}
};

template<typename T>
ostream& operator<<(ostream& os, const Lista<T>& l) {
	os << "{";

	for (int i = 0; i < l.getDb(); i++) {
		os << l.getElem(i);
		if (i < l.getDb() - 1) os << ", ";
	}

	os << "}";
	return os;
}

// Lista, de az elemek tömbben vannak tárolva
template<typename T>
class TombLista : public Lista<T> {
private:
	int db;
	T* elemek;
public:
	// konstruktor, ami üres listát hoz létre
	TombLista() {
		db = 0;
		elemek = nullptr;
	}

	// elem hozzáfûzése
	void hozzafuz(const T& uj_elem) {
		// új terület foglalása
		T* uj_elemek = new T[db + 1];

		// régi elemek másolása
		for (int i = 0; i < db; i++)
			uj_elemek[i] = elemek[i];

		// régi tömb törlése
		delete[] elemek;

		// régi tömb kicserélése az újra
		elemek = uj_elemek;

		// új elem beírása
		elemek[db] = uj_elem;

		// darabszám növelése
		db++;
	}

	virtual T getElem(int index) const {
		return elemek[index];
	}


	virtual void setElem(int index, const T& ertek) {
		elemek[index] = ertek;
	}

	int getDb() const {
		return db;
	}


	// destruktor
	~TombLista() {
		if(elemek!=nullptr)
			delete[] elemek;
	}
};

template<typename T>
void rendez(Lista<T> &lista) {
	for (int i = 0; i < lista.getDb(); i++) {
		for (int j = 0; j < lista.getDb() - 1; j++) {
			if (lista.getElem(j) > lista.getElem(j + 1)) {
				T tmp = lista.getElem(j);
				lista.setElem(j, lista.getElem(j + 1));
				lista.setElem(j + 1, tmp);
			}
		}
	}
}

int main() {
	// intek tárolása
	TombLista<int> l1;
	l1.hozzafuz(3);
	l1.hozzafuz(8);
	l1.hozzafuz(-123);

	l1.setElem(1, 10);

	rendez(l1);

	cout << l1 << endl;

	// sztringek
	TombLista<string> sztringek;
	sztringek.hozzafuz("ez ");
	sztringek.hozzafuz("egy ");
	sztringek.hozzafuz("sztring lista");
	cout << sztringek << endl;

	return 0;
}