#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cout.tie(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	vector<int>x;
	int t;
	cin >> t;
	while (t--) {
		int l;
		cin >> l;
		x.push_back(l);
	}
	int ans;
	cin >> ans;
	sort(x.begin(), x.end());
	int n, m;
	n = 0;
	int cnt = 0;
	m = x.size() - 1;
	while (n < m) {
		if (ans == x[n] + x[m]) {
			cnt++;
			n++;
			m--;
		}
		else if (ans > x[n] + x[m]) {
			n++;
		}
		else {
			m--;
		}
	}
	cout << cnt;
}