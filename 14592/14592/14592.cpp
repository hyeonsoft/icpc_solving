#include <iostream>
//14953 Æ÷ÇÔ
using namespace std;

int main() {
	int a = 0, b = 2147483647, c = 2147483647;
	int n, l = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, e, f;
		cin >> d >> e >> f;
		if (a < d) {
			a = d;
			b = e;
			c = f;
			l = i;
			continue;
		}
		if (a == d && e < b) {
			b = e;
			c = f;
			l = i;
			continue;
		}
		if (a == d && e == b && f < c) {
			c = f;
			l = i;
			continue;
		}
	}
	cout << l + 1;
}