#include <iostream>
#include <string>

using namespace std;

int main() {
	while (1) {
		string a;
		cin >> a;
		if (a == "0")break;
		bool tmp = 0;
		for (int i = 0; i < a.length() / 2; i++) {
			if (a[i] != a[a.length() - i - 1]) {
				tmp = true;
				break;
			}
		}
		cout << (tmp ? "no" : "yes")<<'\n';
	}
}