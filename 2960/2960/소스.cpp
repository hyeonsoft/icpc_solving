#include <iostream>

using namespace std;

bool notprime[4000001]{ 0 };
int primes[300000];
int made{ 1 };
int j;
int primemake(int m) {
	if (m > made) {
		made = m;
		for (int i = 2; i <= m; i++) {
			if (!notprime[i]) {
				for (int u = 2; u*i <= m; u++) {
					notprime[u*i] = 1;
				}
			}
		}
	}
	return -1;
}
int main() {
	notprime[1] = 1;
	primemake(4000000);
	for (int i = 2; i <= 4000000; i++) {
		if (!notprime[i]) {
			primes[j++] = i;
		}
	}
	int k;
	cin >> k;
	int cnt = 0;
	int a;
	for (int i = 0; primes[i] <= k&&i<j; i++) {
		a = 0;
		for (int x = i; x < j&&a <= k; x++) {
			a += primes[x];
			if (a == k) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}