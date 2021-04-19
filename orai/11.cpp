#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Lista {
public:
	virtual int getLength() const = 0; // elemek sz�m�nak lek�r�se
	virtual T getElement(int k) const = 0; // k-adik elem lek�r�se
	virtual void setElement(int k, const T& new_value) = 0; // k-adik elem fel�l�r�sa
	virtual void addElement(const T& new_element) = 0; // �j elem lista v�g�hez f�z�se
	virtual void del(int k) = 0;
	virtual void unique() = 0;
	virtual ~Lista() {}
};

// lista ki�r�sa tetsz�leges ostream-re
// form�tum: [elem1, elem2, elem3]
template<typename T>
ostream& operator<<(ostream &os, const Lista<T>& l) {
	os << "[";
	for (int i = 0; i < l.getLength(); i++) {
		os << l.getElement(i);
		if (i == l.getLength() - 1) // utols� elem ut�n
			os << "]";
		else
			os << ", ";
	}
	return os;
}

// l�cszem strukt�ra
template<typename T>
struct Lancszem {
	T adat; // t�rolt elem
	Lancszem<T> *kovetkezo; // k�vetkez� l�ncszemre mutat� pointer
};

// l�ncolt lista
template<typename T>
class LancoltLista : public Lista<T> {
private:
	Lancszem<T>* elso; // els� l�ncszemre mutat� pointer
public:

	// �res list�t l�trehoz� konstruktor
	LancoltLista() {
		elso = nullptr; // C-ben a NULL
	}

	// elemek sz�m�nak lek�r�se
	int getLength() const {
		int len = 0;

		// bej�r�s
		Lancszem<T>* ptr = elso; // elindulunk az elej�r�l
		while (ptr!=nullptr){
			// k�vetkez� l�ncszemre ugr�s
			ptr = ptr->kovetkezo; // ua. mint: ptr = (*ptr).kovetkezo;

			// sz�ml�l� n�vel�se
			len++;
		}

		return len;
	}

	// k-adik elem lek�r�se
	T getElement(int k) const {
		Lancszem<T>* ptr = elso;
		for (int i = 0; i < k; i++)
			ptr = ptr->kovetkezo;
		return ptr->adat;
	}

	// k-adik elem fel�l�r�sa
	void setElement(int k, const T& new_value) {
		Lancszem<T>* ptr = elso;
		for (int i = 0; i < k; i++)
			ptr = ptr->kovetkezo;
		ptr->adat = new_value;
	}

	// �j elem lista v�g�hez f�z�se
	void addElement(const T& new_element) {
		// �j elem be�ll�t�sa
		Lancszem<T>* uj = new Lancszem<T>;
		uj->adat = new_element;
		uj->kovetkezo = nullptr;

		// spec. eset: els� l�ncszem hozz�f�z�se
		if (elso == nullptr) {
			elso = uj;
			return;
		}

		// �lt. eset (van megel�z� l�ncszem)
		// utols� l�ncszem megkeres�se
		Lancszem<T> *utolso = elso;
		while (utolso->kovetkezo != nullptr)
			utolso = utolso->kovetkezo;
		utolso->kovetkezo = uj;
	}

	void del(int k) {
		// spec. eset: legels� l�ncszem t�rl�se
		if (k == 0) {
			Lancszem<T>* torlendo = elso;
			elso = torlendo->kovetkezo;
			delete torlendo;
			return;
		}

		// �lt. eset: a t�rlend� elem el�tt is van l�ncszem
		Lancszem<T>* megelozo = elso; // a t�rlend� elem el�tti l�ncszem
		for (int i = 0; i < k - 1; i++)
			megelozo = megelozo->kovetkezo;
		Lancszem<T>* torlendo = megelozo->kovetkezo; // t�rlend� l�ncszem
		megelozo->kovetkezo = megelozo->kovetkezo->kovetkezo; // a t�rlend� l�ncszem "�tugr�sa"
		delete torlendo;
	}

	void unique() {
		// lista bej�r�s h�tulr�l (�tgondolni, hogy mi�rt)
		for (int i = getLength() - 1; i >= 0; i--) {
			// ha az i-edik elemet megel�zi ugyanolyan elem,
			// akkor az i-edik elemet t�r�lni kell
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
			Lancszem<T> *tmp = ptr->kovetkezo; // "biztons�gi ment�s"
			delete ptr;
			ptr = tmp;
		}
	}
};

int main() {
	// nevek beolvas�sa
	LancoltLista<string> nevek;
	while (1) {
		string nev;
		cout << "irjon be egy nevet: ";
		getline(cin, nev);

		if (nev == "")
			break;

		nevek.addElement(nev);
	}

	// duplik�tumok t�rl�se
	nevek.unique();

	// eredm�ny ki�r�sa
	cout << nevek << endl;

	return 0;
}