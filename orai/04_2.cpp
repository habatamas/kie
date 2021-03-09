#include <iostream>
#include <string>

using namespace std;

// egy sztring adott kezdet�-e
// pl. forr�sk�d egy adott sora "//"-rel kezd�dik-e
bool startswith(const string &str, const string &kezdet) {
	return str.find(kezdet) == 0;
}

// sztring megford�t�sa
void visszafele(string &str) {
	// n-db karakterb�l �ll a sztring
	int n = str.length();

	// karakterek kicser�l�se
	// melyik index� karaktereket kell kicser�lni?
	
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
	// str l�trehoz�sa, �rt�kad�s
	string s1 = "hello";

	cout << s1 << endl;
	cout << s1.length() << endl;
	
	s1 = "bello";

	cout << s1 << endl;

	// beolvas�s sztringbe
	cout << "irj be egy sort: " << endl;
	string sor;
	getline(cin, sor); // soronk�nti beolvas�s
	// cin >> sor; // szavank�nti beolvas�s
	cout << "a beirt sor: " << sor << endl;

	if (palindrom(sor)) {
		cout << "ez egy palindrom" << endl;
	}
	else {
		cout << "ez nem palindrom" << endl;
	}

	// konverzi�
	string szam;
	szam = to_string(3.141592); // sz�mb�l szring
	cout << szam << endl;
	cout << szam.length() << endl;

	int egesz_ertek = stoi("123"); // sztringb�l eg�sz
	double tort_ertek = stod("3.123"); // sztringb�l double

	// sztringek �sszef�z�se
	string s2 = " BME";
	string s3 = "hello " + s1 + s2;
	cout << s3 << endl;

	// karakterenk�nti kezel�s
	string s4 = "GPK";
	s4[1] = 'T';
	cout << s4 << endl;

	// sztring darabol�s
	string ido = "15:06";
	string ora = ido.substr(0, 2);
	string perc = ido.substr(3, 2);

	// keres�s a sztringben
	string adatsor = "Gipsz Jakab;BATM4N";
	int talalat = adatsor.find(";");
	string nev = adatsor.substr(0, talalat);
	string neptun = adatsor.substr(talalat + 1); // ha nem adunk meg m�sodik param�tert, akkor v�gig olvassa a sztringet

	// startswith f�ggv�ny teszt
	cout << startswith("valami 123", "//") << endl;
	cout << startswith("// ez egy komment", "//") << endl;

	// megford�t� fv
	string s5 = "sziasztok";
	visszafele(s5);
	cout << s5 << endl;

	return 0;
}