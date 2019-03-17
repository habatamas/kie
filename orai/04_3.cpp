#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Titkosito {
private:
	string kulcs; // melyik betût mire cseréljen

public:
	Titkosito() {
		// kulcs generálása
		kulcs = "abcdefghijklmnopqrstuvwxyz";

		// összekuszálás
		for (int i = 0; i < 1000; i++) {
			// két random elem választása
			int egyik = rand() % 26;
			int masik = rand() % 26;

			// csere
			char tmp = kulcs[egyik];
			kulcs[egyik] = kulcs[masik];
			kulcs[masik] = tmp;
		}
	}

	// kulcs getter
	string getKulcs() const {
		return kulcs;
	}

	// egy karakter kódolása
	char kodol(char ch) {
		// ha kisbetû, akkor kódol
		if ('a' <= ch && ch <= 'z') {
			ch = kulcs[ch - 'a'];
		}

		return ch;
	}

	// egy sztring kódolása
	string kodol(const string &str) {
		string eredmeny;
		for (int i = 0; i < str.size(); i++) {
			eredmeny += kodol(str[i]);
		}
		return eredmeny;
	}

	// egy karakter dekódolása
	char dekodol(char ch) {
		for (int i = 0; i < 26; i++)
			if (ch == kulcs[i])
				return 'a' + i;
		return ch;
	}

	// sztring dekódolása
	string dekodol(const string &str) {
		string eredmeny;
		for (int i = 0; i < str.size(); i++) {
			eredmeny += dekodol(str[i]);
		}
		return eredmeny;
	}

};

int main() {
	// randomgenerátort elindítása
	srand(time(NULL));

	// kulcs teszt
	Titkosito t1;
	cout << t1.getKulcs() << endl;
	string eredeti = "szia ez egy sztring :)";
	string kod = t1.kodol(eredeti);
	cout << kod << endl;
	cout << t1.dekodol(kod) << endl;

	cin.get();
	return 0;

}