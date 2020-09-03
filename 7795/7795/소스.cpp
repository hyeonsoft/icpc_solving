#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve();

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int testcase;
	cin >> testcase;
	while (testcase--)solve();
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a, b;
	while (n--) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	while (m--) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	int cnt{ 0 };
	sort(b.begin(), b.end());
	for (int z : a) {
		cnt += lower_bound(b.begin(), b.end(), z) - b.begin();
	}
	cout << cnt << "\n";
}