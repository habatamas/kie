#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Titkosito {
private:
	string kulcs; // melyik bet�t mire cser�ljen

public:
	Titkosito() {
		// kulcs gener�l�sa
		kulcs = "abcdefghijklmnopqrstuvwxyz";

		// �sszekusz�l�s
		for (int i = 0; i < 1000; i++) {
			// k�t random elem v�laszt�sa
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

	// egy karakter k�dol�sa
	char kodol(char ch) {
		// ha kisbet�, akkor k�dol
		if ('a' <= ch && ch <= 'z') {
			ch = kulcs[ch - 'a'];
		}

		return ch;
	}

	// egy sztring k�dol�sa
	string kodol(const string &str) {
		string eredmeny;
		for (int i = 0; i < str.size(); i++) {
			eredmeny += kodol(str[i]);
		}
		return eredmeny;
	}

	// egy karakter dek�dol�sa
	char dekodol(char ch) {
		for (int i = 0; i < 26; i++)
			if (ch == kulcs[i])
				return 'a' + i;
		return ch;
	}

	// sztring dek�dol�sa
	string dekodol(const string &str) {
		string eredmeny;
		for (int i = 0; i < str.size(); i++) {
			eredmeny += dekodol(str[i]);
		}
		return eredmeny;
	}

};

int main() {
	// randomgener�tort elind�t�sa
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