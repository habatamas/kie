#include <iostream>
#include <string>

using namespace std;

/*
Lista adatszerkezet
- t�bb, ugyanolyan (de tetsz�leges) t�pus� elemet tartalmaz
- a sorrendj�k l�nyeges
- az elemekre indexekkel hivatkozunk (lek�rj�k, fel�l�rjuk)
- �j elem hozz�f�z�se a lista v�g�re
- elemek sz�ma lek�rhet�
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

// Lista, de az elemek t�mbben vannak t�rolva
template<typename T>
class TombLista : public Lista<T> {
private:
	int db;
	T* elemek;
public:
	// konstruktor, ami �res list�t hoz l�tre
	TombLista() {
		db = 0;
		elemek = nullptr;
	}

	// elem hozz�f�z�se
	void hozzafuz(const T& uj_elem) {
		// �j ter�let foglal�sa
		T* uj_elemek = new T[db + 1];

		// r�gi elemek m�sol�sa
		for (int i = 0; i < db; i++)
			uj_elemek[i] = elemek[i];

		// r�gi t�mb t�rl�se
		delete[] elemek;

		// r�gi t�mb kicser�l�se az �jra
		elemek = uj_elemek;

		// �j elem be�r�sa
		elemek[db] = uj_elem;

		// darabsz�m n�vel�se
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
	// intek t�rol�sa
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