#include <iostream>

using namespace std;

template <typename T>
class Lista {
public:
	// lista elemeinek darabsz�ma
	virtual int getMeret() const = 0;

	// adott index� elem lek�r�se
	virtual T getElem(int k) const = 0;

	// adott index� elem fel�l�r�sa
	virtual void setElem(int k, const T &uj_ertek) = 0;

	// besz�r�s adott index� elem el�
	virtual void beszur(int k, const T &uj_ertek) = 0;

	// hozz�f�z�s a lista v�g�hez
	virtual void hozzafuz(const T &uj_elem) = 0;

	// �sszes elem ki�r�sa
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
	LancSzem<T> *elso; // els� l�ncszem

public:
	// �res lista l�trehoz�sa
	LancoltLista() {
		elso = nullptr;
	}

	// lista elemeinek darabsz�ma
	int getMeret() const {
		LancSzem<T> *aktualis = elso;
		int meret = 0;
		while (aktualis != nullptr) {
			aktualis = aktualis->kovetkezo; // k�vetkez�re ugr�s
			meret++;
		}
		return meret;
	}

	// adott index� elem lek�r�se
	virtual T getElem(int k) const {
		LancSzem<T> *aktualis = elso;
		while (k != 0) {
			aktualis = aktualis->kovetkezo;
			k--;
		}
		return aktualis->ertek;
	}

	// adott index� elem fel�l�r�sa
	void setElem(int k, const T &uj_ertek) {
		LancSzem<T> *aktualis = elso;
		while (k != 0) {
			aktualis = aktualis->kovetkezo;
			k--;
		}
		aktualis->ertek = uj_ertek;
	};

	// besz�r
	void beszur(int k, const T &uj_ertek) {
		// �j l�ncszem foglal�sa
		LancSzem<T> *uj_lancszem = new LancSzem<T>;
		uj_lancszem->ertek = uj_ertek;

		// spec: ha a lista legelej�re sz�rjuk be
		if (k == 0) {
			uj_lancszem->kovetkezo = elso;
			elso = uj_lancszem;
			return;
		}

		// k�zbees� helyre sz�r�s
		LancSzem<T> *elozo = elso; // besz�r�s helye el� fog mutatni
		while (k != 1) {
			// ugr�s
			elozo = elozo->kovetkezo;
			k--;
		}

		// besz�r�s
		uj_lancszem->kovetkezo = elozo->kovetkezo;
		elozo->kovetkezo = uj_lancszem;
	}

	// hozz�f�z�s a lista v�g�hez
	void hozzafuz(const T &uj_elem) {
		// �j l�ncszem foglal�sa
		LancSzem<T> *uj_lancszem = new LancSzem<T>;
		uj_lancszem->ertek = uj_elem;
		uj_lancszem->kovetkezo = nullptr;

		// speci�lis eset: legels� elem hozz�f�z�se
		if (getMeret() == 0) {
			elso = uj_lancszem;
			return;
		}

		// utols� elem megkeres�se
		LancSzem<T> *utolso = elso;
		while (utolso->kovetkezo != nullptr) {
			// ugr�s
			utolso = utolso->kovetkezo;
		}

		// �tdr�toz�s
		utolso->kovetkezo = uj_lancszem;
	}

	// destruktor
	~LancoltLista() {
		LancSzem<T> *aktualis=elso;
		while (aktualis != nullptr) {
			// megjegyezz�k a k�vetkez� elem pointer�t
			LancSzem<T> *kovetkezo = aktualis->kovetkezo;

			// l�ncszem t�rl�se
			delete aktualis;

			// k�vetkez�re l�p�s
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