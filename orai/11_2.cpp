#include <iostream>
#include <string>

using namespace std;

class SajatString : public string {
private:
	// adott karakter hányszor fordul elõ
	int hanyszor(char ch) const {
		int count = 0;
		for (int i = 0; i < length(); i++)
			if (operator[](i) == ch)
				count++;
		return count;
	}

public:
	
	SajatString(const char *str) : string(str) {
	}

	SajatString(const SajatString &eredeti) : string(eredeti) {
	}

	bool operator==(const SajatString &masik) {
		for (int i = 0; i < length(); i++) {
			char ch = operator[](i);

			if (hanyszor(ch) != masik.hanyszor(ch))
				return false;
		}

		for (int i = 0; i < masik.length(); i++) {
			char ch = masik[i];

			if (hanyszor(ch) != masik.hanyszor(ch))
				return false;
		}

		return true;
	}
};

int main() {
	SajatString s1 = "teszt";
	SajatString s2 = "szett";
	SajatString s3 = "semmi";
	cout << (s1 == s2) << endl;
	cout << (s1 == s3) << endl;
	cout << (s2 == s3) << endl;
	cin.get();
	return 0;
}