#include <iostream>
#include <ostream> // kiirat�shoz
#include <vector>

using namespace std;

// egyszer� 3d vektor template
template<typename T>
struct Vektor3d{
	T x, y, z;

	Vektor3d() {
	}

	Vektor3d(T x, T y, T z) : x(x), y(y), z(z) {

	}
};

// vektor ki�r�s�hoz
template<typename T>
ostream& operator<<(ostream& os, const Vektor3d<T> &v) {
	os << '[' << v.x << ';' << v.y << ';' << v.z << ']' << endl;
	return os;
}

template<typename KulcsTipus, typename ErtekTipus>
struct KulcsErtekPar {
	KulcsTipus kulcs;
	ErtekTipus ertek;
};


template<typename KulcsTipus, typename ErtekTipus>
ostream& operator<<(ostream& os,
	const KulcsErtekPar<KulcsTipus, ErtekTipus>& obj) {
	os << obj.kulcs << "->" << obj.ertek << endl;
	return os;
}

template<typename T>
class Lista {
private:
	int meret;
	T* elemek;
public:
	// �res lista l�trehoz�sa
	Lista() {
		meret = 0;
		elemek = nullptr; // ugyanaz NULL
	}

	// copy-konstruktor
	Lista(const Lista& eredeti) {
		meret = eredeti.meret;
		elemek = new T[meret];
		for (int i = 0; i < meret; i++)
			elemek[i] = eredeti.elemek[i];
	}

	void hozzafuz(const T& uj_elem) {
		// �j t�mb foglal�sa
		T* uj_elemek = new T[meret + 1];

		// r�gi adatok �tm�sol�sa �j helyre
		for (int i = 0; i < meret; i++)
			uj_elemek[i] = elemek[i];

		// r�gi t�mb felszabad�t�sa
		delete[] elemek;

		// hozz�f�z�tt adat ->�j t�mbbe
		uj_elemek[meret] = uj_elem;

		// tagv�ltoz�k friss�t�se
		meret++;
		elemek = uj_elemek;
	}

	void beszur(const T& uj_elem, int hova) {
		// �j t�mb foglal�sa
		T* uj_elemek = new T[meret + 1];

		// r�gi adatok �tm�sol�sa
		for (int i = 0; i < meret; i++) {
			if (i<hova)
				uj_elemek[i] = elemek[i];
			else
				uj_elemek[i + 1] = elemek[i];
		}

		// felszab.
		delete[] elemek;

		// �tm�soljuk az �j adatot
		uj_elemek[hova] = uj_elem;
	
		// v�ltoz�k friss�t�se
		meret++;
		elemek = uj_elemek;
	}

	// indexel�s (�rt�k lek�r�se)
	T operator[](int i) const {
		return elemek[i];
	}

	// indexel�s (�rt�k be�r�sa)
	T& operator[](int i) {
		return elemek[i];
	}

	// m�ret getter
	int getMeret() const {
		return meret;
	}

	// elem t�rl�se
	void torol(int honnan) {
		meret--;
		for (int i = honnan; i < meret; i++)
			elemek[i] = elemek[i + 1];
	}

	// ki�r�s
	friend ostream& operator<<(ostream& os, const Lista& l) {
		os << "[";
		for (int i = 0; i < l.meret; i++) {
			os << l.elemek[i];
			if (i < l.meret - 1)
				os << "; ";
			else
				os << "]";
		}
		return os;
	}

	// �sszef�z�s
	Lista operator+(const Lista &masik) const {
		Lista uj = *this; // �nmagunk m�solata

		for (int i = 0; i < masik.meret; i++)
			uj.hozzafuz(masik[i]);

		return uj;
	}

	~Lista() {
		delete[] elemek; // itt az se baj, ha elemek==nullptr
	}
};

template<typename KulcsTipus, typename ErtekTipus>
class Szotar {
private:
	Lista<KulcsErtekPar<KulcsTipus, ErtekTipus>> parok;
public:
	// be�r�s
	ErtekTipus& operator[](const KulcsTipus& kulcs) {
		for (int i = 0; i < parok.getMeret(); i++) {
			if (parok[i].kulcs == kulcs) {
				return parok[i].ertek;
			}
		}
		// ha nincs tal�lat...
		parok.hozzafuz(KulcsErtekPar<KulcsTipus, ErtekTipus>());
		parok[parok.getMeret() - 1].kulcs = kulcs;
		return parok[parok.getMeret() - 1].ertek;
	}

	// kiolvas�s
	ErtekTipus operator[](const KulcsTipus& kulcs) const {
		for (int i = 0; i < parok.getMeret(); i++) {
			if (parok[i].kulcs == kulcs) {
				return parok[i].ertek;
			}
		}
		// hiba: nincs ilyen elem
	}

	friend ostream& operator<<(ostream& os, const Szotar& sz) {
		for (int i = 0; i < sz.parok.getMeret(); i++) {
			os << sz.parok[i].kulcs << '\t' << sz.parok[i].ertek << endl;
		}
		return os;
	}
};

int main() {
	Vektor3d<int> v1(1,2,3);
	cout << v1 << endl;

	Vektor3d<double> v2(3.14,1.11,2.22);
	cout << v2 << endl;

	KulcsErtekPar<int, string> ember;
	ember.kulcs = 123;
	ember.ertek = "Joska";
	cout << ember << endl;

	Lista<int> l1;
	l1.hozzafuz(3);
	l1.hozzafuz(4);
	cout << l1[0] << endl;
	cout << l1[1] << endl;
	l1[0] = 123;
	cout << l1[0] << endl;

	l1.hozzafuz(11111);
	cout << l1 << endl;
	l1.hozzafuz(22222);
	cout << l1 << endl;

	l1.beszur(444444, 2);
	cout << l1 << endl;
	l1.torol(1);
	cout << l1 << endl;

	Lista<int> l2 = l1;
	cout << l2 << endl;

	cout << l1 + l2 << endl;

	cout << "hello" << endl;

	Szotar<int, string> emberek;
	emberek[1123] = "Joska";
	emberek[1211] = "Pista";
	cout << emberek[1123] << endl;
	cout << emberek[1211] << endl;

	Szotar<string, int> varosok;
	varosok["Budapest"] = 2500000;
	varosok["Bergengocia"] = 2000;

	cout << varosok["Budapest"] << endl;
	cout << varosok["Bergengocia"] << endl;

	varosok["Bergengocia"] = 123;
	cout << varosok["Bergengocia"] << endl;

	cout << varosok << endl;
	
	// STL
	vector<int> v; 
	v.push_back(113);
	v.push_back(234);
	v.push_back(456);
	v[1] = 11122223333;
	
	for (auto& elem : v) {
		cout << elem << endl;
	}

	return 0;
}