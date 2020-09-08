#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int diff = 50;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int d=0;
		for (int k = 0; k < a.length(); k++) {
			if (b[i + k] != a[k])d++;
		}
		diff = d < diff ? d : diff;
	}
	cout << diff;
}