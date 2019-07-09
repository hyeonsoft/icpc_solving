#include <iostream>

using namespace std;

bool notprime[1000001]{ 0 };
int made{ 1 };
void primemake(int m) {
	if (m > made) {
		made = m;
		for (int i = 2; i <= m;i++) {
			if (!notprime[i]) {
				for (int u = 2; u*i <= m; u++) {
					notprime[u*i] = 1;
				}
			}
		}
	}
}
int main() {
	notprime[1] = 1;
	int i, j;
	cin >> i >> j;
	primemake(1000000);
	for (; i <= j; i++) {
		if (!notprime[i]) {
			cout << i << "\n";
		}
	}
}