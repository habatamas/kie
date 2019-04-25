#include <iostream>

using namespace std;

template <typename T>
class Lista {
public:
	// lista elemeinek darabszáma
	virtual int getMeret() const = 0;

	// adott indexû elem lekérése
	virtual T getElem(int k) const = 0;

	// adott indexû elem felülírása
	virtual void setElem(int k, const T &uj_ertek) = 0;

	// beszúrás adott indexû elem elé
	virtual void beszur(int k, const T &uj_ertek) = 0;

	// hozzáfûzés a lista végéhez
	virtual void hozzafuz(const T &uj_elem) = 0;

	// összes elem kiírása
	void kiir() const {
		for (int i = 0; i < getMeret(); i++)
			cout << getElem(i) << ";    ";
		cout << endl;
	}

	// destruktor
	virtual ~Lista() {
	}
};

template <typename T>
struct LancSzem {
	T ertek;
	LancSzem<T> *kovetkezo;
};

template <typename T>
class LancoltLista : public Lista<T> {
private:
	LancSzem<T> *elso; // elsõ láncszem

public:
	// üres lista létrehozása
	LancoltLista() {
		elso = nullptr;
	}

	// lista elemeinek darabszáma
	int getMeret() const {
		LancSzem<T> *aktualis = elso;
		int meret = 0;
		while (aktualis != nullptr) {
			aktualis = aktualis->kovetkezo; // következõre ugrás
			meret++;
		}
		return meret;
	}

	// adott indexû elem lekérése
	virtual T getElem(int k) const {
		LancSzem<T> *aktualis = elso;
		while (k != 0) {
			aktualis = aktualis->kovetkezo;
			k--;
		}
		return aktualis->ertek;
	}

	// adott indexû elem felülírása
	void setElem(int k, const T &uj_ertek) {
		LancSzem<T> *aktualis = elso;
		while (k != 0) {
			aktualis = aktualis->kovetkezo;
			k--;
		}
		aktualis->ertek = uj_ertek;
	};

	// beszúr
	void beszur(int k, const T &uj_ertek) {
		// új láncszem foglalása
		LancSzem<T> *uj_lancszem = new LancSzem<T>;
		uj_lancszem->ertek = uj_ertek;

		// spec: ha a lista legelejére szúrjuk be
		if (k == 0) {
			uj_lancszem->kovetkezo = elso;
			elso = uj_lancszem;
			return;
		}

		// közbeesõ helyre szúrás
		LancSzem<T> *elozo = elso; // beszúrás helye elé fog mutatni
		while (k != 1) {
			// ugrás
			elozo = elozo->kovetkezo;
			k--;
		}

		// beszúrás
		uj_lancszem->kovetkezo = elozo->kovetkezo;
		elozo->kovetkezo = uj_lancszem;
	}

	// hozzáfûzés a lista végéhez
	void hozzafuz(const T &uj_elem) {
		// új láncszem foglalása
		LancSzem<T> *uj_lancszem = new LancSzem<T>;
		uj_lancszem->ertek = uj_elem;
		uj_lancszem->kovetkezo = nullptr;

		// speciális eset: legelsõ elem hozzáfûzése
		if (getMeret() == 0) {
			elso = uj_lancszem;
			return;
		}

		// utolsó elem megkeresése
		LancSzem<T> *utolso = elso;
		while (utolso->kovetkezo != nullptr) {
			// ugrás
			utolso = utolso->kovetkezo;
		}

		// átdrótozás
		utolso->kovetkezo = uj_lancszem;
	}

	// destruktor
	~LancoltLista() {
		LancSzem<T> *aktualis=elso;
		while (aktualis != nullptr) {
			// megjegyezzük a következõ elem pointerét
			LancSzem<T> *kovetkezo = aktualis->kovetkezo;

			// láncszem törlése
			delete aktualis;

			// következõre lépés
			aktualis = kovetkezo;
		}
	}


};

int main() {
	cout << "hello" << endl;

	LancoltLista<int> l;
	l.hozzafuz(1);
	l.hozzafuz(2);
	l.hozzafuz(3);
	l.setElem(1, 99);
	l.kiir();
	l.beszur(2, 1234);
	l.kiir();

	cin.get();
	return 0;

}