#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
Darabolo oszt�ly
- l�trehoz�skor megadunk egy daraboland� sztringet �s az elv�laszt� karakterl�ncot
- tagfv: megmondja, hogy h�ny adat "oszlop" van az adott sorban
- tagfv: megmondja, hogy az i-edik oszlop micsoda
*/
class Darabolo {
private:
	string str; // kompoz�ci�
	string *sep; // aggreg�ci�
public:
	Darabolo(const string &str, const string &sep) {
		this->str = str;
		this->sep = new string(sep);
	}

	Darabolo(const Darabolo& eredeti) {
		str = eredeti.str;
		sep = new string(*(eredeti.sep));
	}

	// visszaadja a sorban tal�lhat� cell�k sz�m�t
	int getMeret() const {
		// elv�laszt�k sz�ma + 1
		int db = 0;

		int offset = 0;
		while (str.find(*sep, offset) != -1) {
			db++;
			int talalat = str.find(*sep, offset);
			offset = talalat + sep->length();
		}

		return db+1;
	}

	string getCella(int i) const {
		// meg kell tal�lni az i-edik �s az i+1-edik elv�laszt�t

		int db = 0;

		// a k�v�nt cella els� karakter�re �ll�tja az offsetet
		int offset = 0;
		while (db<i) {
			db++;
			int talalat = str.find(*sep, offset);
			offset = talalat + sep->length();
		}

		// a k�v�nt cella ut�ni r�sz
		int vege_offset = str.find(*sep, offset); // -1 is lehet

		// visszat�r�s a k�ztes r�sszel
		if (vege_offset == -1) // legutols�, sorv�gi cella
			return str.substr(offset);
		return str.substr(offset, vege_offset - offset); // �lt. eset
	}

	~Darabolo() {
		delete sep;
	}
};

/*
CSVolvaso oszt�ly
konstruktora megkapja a f�jlnevet �s az elv�laszt� karakterl�ncot
getCella(sor,oszlop) visszat�r az adott cell�val
*/
class CSVolvaso {
private:
	string fajlnev;
	string elv;
public:
	CSVolvaso(const string& fajlnev, const string& elv) {
		this->fajlnev = fajlnev;
		this->elv = elv;
	}

	CSVolvaso(const CSVolvaso& eredeti) {
		this->fajlnev = eredeti.fajlnev;
		this->elv = eredeti.elv;
	}

	string getCella(int sorIndex, int oszlopIndex) const {
                // Megjegyz�s: nem t�l hat�kony megold�s minden cella kiolvas�skor �jra megnyitni a f�jlt.
                // gyakorl�sk�pp: alak�tsuk �t az oszt�lyt �gy, hogy megjegyezze a legutols� lek�rt cell�t, �s csak akkor nyissa �jra a f�jlt, ha kor�bbi cell�ra szeretn�nk visszat�rni! 


		// f�jl megnyit�sa
		ifstream fajl;
		fajl.open(fajlnev);
		
		// adott sor beolvas�sa
		string sor;
		for(int i=0; i<=sorIndex; i++)
			getline(fajl,sor);

		// sorb�l ki kell v�lasztani a megfelel� cell�t
		Darabolo d(sor, elv);
		string cella = d.getCella(oszlopIndex);
		return cella;
	}

	~CSVolvaso() {
		// ide nem kell semmi, mert nincs new
	}
};

int main() {
	string sor = "adat1->ez itt egy tobb szobol allo adat->adat3";
	string elv = "->";
	Darabolo d(sor, elv);

	d.getCella(2);

	cout << d.getMeret() << " db cella van a sorban." << endl;
	for (int i = 0; i < d.getMeret(); i++) {
		cout << d.getCella(i) << endl;
	}

	CSVolvaso olvaso("adatok.csv", ";");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << olvaso.getCella(i, j) << endl;
		}
	}

	// transzpon�l�s
	ofstream fajl;
	//fajl.open("transzponalt.csv",ios_base::app); // HOZZ�F�Z�S
	fajl.open("transzponalt.csv"); // fel�l�r�s
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(j!=0) fajl << ";";
			fajl << olvaso.getCella(j, i);
		}
		fajl << endl;
	}
	fajl.close();

	cout << "hello MOGI" << endl;
	return 0;
}
