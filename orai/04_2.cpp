#include <iostream>
#include <string>

using namespace std;

// egy sztring adott kezdetû-e
// pl. forráskód egy adott sora "//"-rel kezdõdik-e
bool startswith(const string &str, const string &kezdet) {
	return str.find(kezdet) == 0;
}

// sztring megfordítása
void visszafele(string &str) {
	// n-db karakterbõl áll a sztring
	int n = str.length();

	// karakterek kicserélése
	// melyik indexû karaktereket kell kicserélni?
	
	for (int i = 0; i < n / 2; i++) {
		char tmp = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = tmp;
	}
}

bool palindrom(const string &str) {
	string forditott = str;
	visszafele(forditott);

	return str == forditott;
}

int main() {
	// str létrehozása, értékadás
	string s1 = "hello";

	cout << s1 << endl;
	cout << s1.length() << endl;
	
	s1 = "bello";

	cout << s1 << endl;

	// beolvasás sztringbe
	cout << "irj be egy sort: " << endl;
	string sor;
	getline(cin, sor); // soronkénti beolvasás
	// cin >> sor; // szavankénti beolvasás
	cout << "a beirt sor: " << sor << endl;

	if (palindrom(sor)) {
		cout << "ez egy palindrom" << endl;
	}
	else {
		cout << "ez nem palindrom" << endl;
	}

	// konverzió
	string szam;
	szam = to_string(3.141592); // számból szring
	cout << szam << endl;
	cout << szam.length() << endl;

	int egesz_ertek = stoi("123"); // sztringbõl egész
	double tort_ertek = stod("3.123"); // sztringbõl double

	// sztringek összefûzése
	string s2 = " BME";
	string s3 = "hello " + s1 + s2;
	cout << s3 << endl;

	// karakterenkénti kezelés
	string s4 = "GPK";
	s4[1] = 'T';
	cout << s4 << endl;

	// sztring darabolás
	string ido = "15:06";
	string ora = ido.substr(0, 2);
	string perc = ido.substr(3, 2);

	// keresés a sztringben
	string adatsor = "Gipsz Jakab;BATM4N";
	int talalat = adatsor.find(";");
	string nev = adatsor.substr(0, talalat);
	string neptun = adatsor.substr(talalat + 1); // ha nem adunk meg második paramétert, akkor végig olvassa a sztringet

	// startswith függvény teszt
	cout << startswith("valami 123", "//") << endl;
	cout << startswith("// ez egy komment", "//") << endl;

	// megfordító fv
	string s5 = "sziasztok";
	visszafele(s5);
	cout << s5 << endl;

	return 0;
}