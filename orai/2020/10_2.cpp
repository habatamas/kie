#include <iostream>

using namespace std;

// Lista: elemek sorrendben, sorszám (index) alapján elérve

template <typename T>
class Lista {
public:
	virtual T getElem(int index) const = 0;
	virtual int getMeret() const = 0;
	virtual void setEelem(int index, const T& ertek) = 0;
	virtual void hozzafuz(const T& ertek) = 0;

	friend ostream& operator<<(ostream& os, const Lista& l) {
		os << "[";
		for (int i = 0; i < l.getMeret(); i++) {
			os << l.getElem(i);
			if (i < l.getMeret() - 1)
				os << "; ";
		}
		os << "]";
		return os;
	}

	virtual ~Lista() {
	};
};

// lista konkrét megvalósítása dinamikus tömbbel
template <typename T>
class TombLista : public Lista<T> {
private:
	int db;
	T* elemek;
public:
	TombLista(): db(0), elemek(nullptr) {

	}

	virtual T getElem(int index) const {
		return elemek[index];
	};

	virtual int getMeret() const {
		return db;
	};

	virtual void setEelem(int index, const T& ertek) {
		elemek[index] = ertek;
	};

	virtual void hozzafuz(const T& ertek) {
		T* uj_tomb = new T[db + 1];
		for (int i = 0; i < db; i++)
			uj_tomb[i] = elemek[i];
		uj_tomb[db] = ertek;
		delete[] elemek;
		db++;
		elemek = uj_tomb;
	};

	~TombLista() {
		delete[] elemek;
	}
};

// láncszem
template <typename T>
struct LancSzem {
	T adat;
	LancSzem<T>* kovetkezo; // következõ láncszemre mutat
	                        // vagy nullptr, ha ez az utolsó szem
};

// láncolt lista
template <typename T>
class LancoltLista : public Lista<T> {
private:
	LancSzem<T>* elso;
public:
	LancoltLista() : elso(nullptr) {
	}

	virtual T getElem(int index) const {
		LancSzem<T>* aktualis = elso;
		for (int i = 0; i < index; i++)
			aktualis = aktualis->kovetkezo; // következõ láncszemre ugrás
		return aktualis->adat;
	}

	virtual int getMeret() const {
		int meret = 0;
		LancSzem<T>* aktualis = elso;
		while (aktualis != nullptr) {
			aktualis = aktualis->kovetkezo;
			meret++;
		}
		return meret;
	}

	virtual void setEelem(int index, const T& ertek) {
		LancSzem<T>* aktualis = elso;
		while (index--) // rondaság
			aktualis = aktualis->kovetkezo; // ugrás
		aktualis->adat = ertek;
	}

	virtual void hozzafuz(const T& ertek) {
		// új láncszem létrehozása
		LancSzem<T>* uj_szem = new LancSzem<T>;
		uj_szem->adat = ertek;
		uj_szem->kovetkezo = nullptr;

		// ha ez a legelsõ elem
		if (elso == nullptr) {
			elso = uj_szem;
			return;
		}

		// utolsó elemig el kell ugrálni
		LancSzem<T>* aktualis = elso;
		while (aktualis->kovetkezo != nullptr)
			aktualis = aktualis->kovetkezo;

		// elõzõ végéhez fûzés
		aktualis->kovetkezo = uj_szem;
	}

	~LancoltLista() {
		LancSzem<T>* aktualis = elso;
		while (aktualis != nullptr) {
			LancSzem<T>* kovetkezo = aktualis->kovetkezo;
			delete aktualis;
			aktualis = kovetkezo;
		}
	}
};

template<typename T>
void rendez(Lista<T> &lista) {
	for (int i = 0; i < lista.getMeret(); i++) {
		for (int j = 0; j < lista.getMeret() - 1; j++) {
			if (lista.getElem(j)>lista.getElem(j+1)) {
				T tmp = lista.getElem(j);
				lista.setEelem(j, lista.getElem(j + 1));
				lista.setEelem(j + 1, tmp);
			}
		}
	}
}

int main() {
	TombLista<int> szamok; // !!!!!

	szamok.hozzafuz(7);
	szamok.hozzafuz(8);
	szamok.hozzafuz(2);
	rendez(szamok);

	cout << szamok << endl;

	for (int i = 0; i < szamok.getMeret(); i++) {
		cout << szamok.getElem(i) << endl;
	}
	return 0;
}