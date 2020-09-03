#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void testcase(int k) {
	int n;
	cin >> n;
	int a = 0;
	int sum = 0;
	vector<int>candy;
	while (n--) {
		int x;
		cin >> x;
		candy.push_back(x);
		a = a ^ x;
		sum += x;
	}
	if (a != 0)cout << "Case #" << k << ": NO\n";
	else {
		sort(candy.begin(), candy.end());
		cout << "Case #" << k << ": " << sum - candy[0] << "\n";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++) {
		testcase(i);
	}
}