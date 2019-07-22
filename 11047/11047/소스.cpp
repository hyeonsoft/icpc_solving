//Coin 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> coinvalue;
	int n, k;
	cin >> n >> k;
	while (n--) {
		int a;
		cin >> a;
		coinvalue.push_back(a);
	}
	sort(coinvalue.begin(), coinvalue.end());
	int sum=0;
	for (int i = coinvalue.size() - 1; i >= 0; i--) {
		sum += k / coinvalue[i];
		k -= k / coinvalue[i] * coinvalue[i];
	}
	cout << sum;
}