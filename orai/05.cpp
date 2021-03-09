#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
Darabolo osztály
- létrehozáskor megadunk egy darabolandó sztringet és az elválasztó karakterláncot
- tagfv: megmondja, hogy hány adat "oszlop" van az adott sorban
- tagfv: megmondja, hogy az i-edik oszlop micsoda
*/
class Darabolo {
private:
	string str; // kompozíció
	string *sep; // aggregáció
public:
	Darabolo(const string &str, const string &sep) {
		this->str = str;
		this->sep = new string(sep);
	}

	Darabolo(const Darabolo& eredeti) {
		str = eredeti.str;
		sep = new string(*(eredeti.sep));
	}

	// visszaadja a sorban található cellák számát
	int getMeret() const {
		// elválasztók száma + 1
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
		// meg kell találni az i-edik és az i+1-edik elválasztót

		int db = 0;

		// a kívánt cella elsõ karakterére állítja az offsetet
		int offset = 0;
		while (db<i) {
			db++;
			int talalat = str.find(*sep, offset);
			offset = talalat + sep->length();
		}

		// a kívánt cella utáni rész
		int vege_offset = str.find(*sep, offset); // -1 is lehet

		// visszatérés a köztes résszel
		if (vege_offset == -1) // legutolsó, sorvégi cella
			return str.substr(offset);
		return str.substr(offset, vege_offset - offset); // ált. eset
	}

	~Darabolo() {
		delete sep;
	}
};

/*
CSVolvaso osztály
konstruktora megkapja a fájlnevet és az elválasztó karakterláncot
getCella(sor,oszlop) visszatér az adott cellával
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
                // Megjegyzés: nem túl hatékony megoldás minden cella kiolvasáskor újra megnyitni a fájlt.
                // gyakorlásképp: alakítsuk át az osztályt úgy, hogy megjegyezze a legutolsó lekért cellát, és csak akkor nyissa újra a fájlt, ha korábbi cellára szeretnénk visszatérni! 


		// fájl megnyitása
		ifstream fajl;
		fajl.open(fajlnev);
		
		// adott sor beolvasása
		string sor;
		for(int i=0; i<=sorIndex; i++)
			getline(fajl,sor);

		// sorból ki kell választani a megfelelõ cellát
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

	// transzponálás
	ofstream fajl;
	//fajl.open("transzponalt.csv",ios_base::app); // HOZZÁFÛZÉS
	fajl.open("transzponalt.csv"); // felülírás
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
