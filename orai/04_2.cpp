#include <iostream>
#include <string>

using namespace std;

int elofordulasok_szama(const string &miben, const string &mit) {
	int honnan = 0;
	int szamlalo = 0;

	while (miben.find(mit, honnan) != -1) {
		szamlalo++;
		honnan = miben.find(mit, honnan) + mit.size();
	}

	return szamlalo;
}

string *darabol(const string &mit, const string &elv) {
	// tömb foglalása
	int n = elofordulasok_szama(mit, elv) + 1; // hány db?
	string *darabok = new string[n];

	// darabolás
	int honnan = 0;
	int i = 0;
	while (mit.find(elv, honnan) != -1) {
		int talalat = mit.find(elv, honnan);
		
		darabok[i] = mit.substr(honnan, talalat - honnan);
		i++;

		honnan = talalat + elv.size();
	}

	// utolsó darab
	darabok[i] = mit.substr(honnan);

	// visszatérés
	return darabok;
}

int main() {
	// string deklarálás
	string s1 = ":)";
	string ures;

	// string kiírása
	cout << s1 << endl;

	// szó beolvasása
	/*string s2;
	cout << "irj be egy sztringet: ";
	cin >> s2;
	cout << s2 << endl;*/

	// sor beolvasása
	string s3;
	cout << "irj be egy sort: ";
	getline(cin, s3);
	cout << "sor: " << s3 << endl;

	// konvertálás
	string s4 = "123";
	int i1 = stoi(s4);
	cout << i1 << endl;

	s4 = "3.141592136";
	double pi = stod(s4);
	cout << pi << endl;

	cout << to_string(3.1415) << endl;

	// string indexelése
	string s5 = "BGE";
	s5[1] = 'M';
	cout << s5 << endl;

	// string hossza
	cout << s4 << "hossza: " << s4.length() << endl;
	cout << s4 << "hossza: " << s4.size() << endl;

	// összefûzés
	string egyik = "MO", masik = "GI";
	string osszefuzve = egyik + masik;
	cout << osszefuzve << endl;

	// részsztring
	string s6 = "ez egy hosszu string";
	cout << s6.substr(7) << endl;
	cout << s6.substr(7, 6) << endl;

	// keresés a sztringben
	string s7 = "ez egy hosszu string, ez nem egy vicc";
	cout << s7.find("egy") << endl;
	cout << s7.find("egy", 10) << endl;
	int index = s7.find(".....###");
	cout << index << endl;

	// elõfordulások száma
	cout << "egy: " << elofordulasok_szama(s7, "egy") << endl;
	cout << "string: " << elofordulasok_szama(s7, "string") << endl;
	cout << "....: " << elofordulasok_szama(s7, "...") << endl;

	// darabolás
	string csv_sor = "1;2;123;981623;valami";
	string *oszlopok = darabol(csv_sor, ";");
	cout << "darabok:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << oszlopok[i] << endl;
	}
	delete[] oszlopok;

	cout << "hello" << endl;
	cin.get();
	return 0;
}