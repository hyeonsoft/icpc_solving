#include <iostream>
using namespace std;
int main() {
	int a[7];
	int b = 7;
	int min = -1;
	int sum = 0;
	while (b--) {
		cin >> a[b];
		if (a[b] % 2) {
			if (min == -1 || min > a[b])min = a[b];
			sum += a[b];
		}
	}
	if (sum)cout << sum << endl;
	cout<< min;

}