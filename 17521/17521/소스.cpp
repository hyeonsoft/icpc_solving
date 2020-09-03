#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long int w;
	cin >> n >> w;
	int back;
	cin >> back;
	n--;
	while (n--) {
		int i;
		cin >> i;
		if (back < i) {
			w = (w / back)*i + w % back;
		}
		else {
			;
		}
		back = i;
	}
	cout << w;
}