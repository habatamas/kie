#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Lista {
public:
	virtual int getLength() const = 0; // elemek számának lekérése
	virtual T getElement(int k) const = 0; // k-adik elem lekérése
	virtual void setElement(int k, const T& new_value) = 0; // k-adik elem felülírása
	virtual void addElement(const T& new_element) = 0; // új elem lista végéhez fûzése
	virtual void del(int k) = 0;
	virtual void unique() = 0;
	virtual ~Lista() {}
};

// lista kiírása tetszõleges ostream-re
// formátum: [elem1, elem2, elem3]
template<typename T>
ostream& operator<<(ostream &os, const Lista<T>& l) {
	os << "[";
	for (int i = 0; i < l.getLength(); i++) {
		os << l.getElement(i);
		if (i == l.getLength() - 1) // utolsó elem után
			os << "]";
		else
			os << ", ";
	}
	return os;
}

// lácszem struktúra
template<typename T>
struct Lancszem {
	T adat; // tárolt elem
	Lancszem<T> *kovetkezo; // következõ láncszemre mutató pointer
};

// láncolt lista
template<typename T>
class LancoltLista : public Lista<T> {
private:
	Lancszem<T>* elso; // elsõ láncszemre mutató pointer
public:

	// üres listát létrehozó konstruktor
	LancoltLista() {
		elso = nullptr; // C-ben a NULL
	}

	// elemek számának lekérése
	int getLength() const {
		int len = 0;

		// bejárás
		Lancszem<T>* ptr = elso; // elindulunk az elejérõl
		while (ptr!=nullptr){
			// következõ láncszemre ugrás
			ptr = ptr->kovetkezo; // ua. mint: ptr = (*ptr).kovetkezo;

			// számláló növelése
			len++;
		}

		return len;
	}

	// k-adik elem lekérése
	T getElement(int k) const {
		Lancszem<T>* ptr = elso;
		for (int i = 0; i < k; i++)
			ptr = ptr->kovetkezo;
		return ptr->adat;
	}

	// k-adik elem felülírása
	void setElement(int k, const T& new_value) {
		Lancszem<T>* ptr = elso;
		for (int i = 0; i < k; i++)
			ptr = ptr->kovetkezo;
		ptr->adat = new_value;
	}

	// új elem lista végéhez fûzése
	void addElement(const T& new_element) {
		// új elem beállítása
		Lancszem<T>* uj = new Lancszem<T>;
		uj->adat = new_element;
		uj->kovetkezo = nullptr;

		// spec. eset: elsõ láncszem hozzáfûzése
		if (elso == nullptr) {
			elso = uj;
			return;
		}

		// ált. eset (van megelõzõ láncszem)
		// utolsó láncszem megkeresése
		Lancszem<T> *utolso = elso;
		while (utolso->kovetkezo != nullptr)
			utolso = utolso->kovetkezo;
		utolso->kovetkezo = uj;
	}

	void del(int k) {
		// spec. eset: legelsõ láncszem törlése
		if (k == 0) {
			Lancszem<T>* torlendo = elso;
			elso = torlendo->kovetkezo;
			delete torlendo;
			return;
		}

		// ált. eset: a törlendõ elem elõtt is van láncszem
		Lancszem<T>* megelozo = elso; // a törlendõ elem elõtti láncszem
		for (int i = 0; i < k - 1; i++)
			megelozo = megelozo->kovetkezo;
		Lancszem<T>* torlendo = megelozo->kovetkezo; // törlendõ láncszem
		megelozo->kovetkezo = megelozo->kovetkezo->kovetkezo; // a törlendõ láncszem "átugrása"
		delete torlendo;
	}

	void unique() {
		// lista bejárás hátulról (átgondolni, hogy miért)
		for (int i = getLength() - 1; i >= 0; i--) {
			// ha az i-edik elemet megelõzi ugyanolyan elem,
			// akkor az i-edik elemet törölni kell
			for (int j = 0; j < i; j++) {
				if (getElement(i) == getElement(j)) {
					del(i);
					break; /// !!!!
				}
			}
		}
	}

	~LancoltLista() {
		Lancszem<T> *ptr = elso;
		while (ptr != nullptr) {
			Lancszem<T> *tmp = ptr->kovetkezo; // "biztonsági mentés"
			delete ptr;
			ptr = tmp;
		}
	}
};

int main() {
	// nevek beolvasása
	LancoltLista<string> nevek;
	while (1) {
		string nev;
		cout << "irjon be egy nevet: ";
		getline(cin, nev);

		if (nev == "")
			break;

		nevek.addElement(nev);
	}

	// duplikátumok törlése
	nevek.unique();

	// eredmény kiírása
	cout << nevek << endl;

	return 0;
}