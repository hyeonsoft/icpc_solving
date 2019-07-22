#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>>a;
	while (n--) {
		int s, e;
		cin >> s >> e;
		a.push_back(pair<int, int>(e, s));
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	int end = -1;
	for (int i = 0; i < a.size(); i++) {
		if (end <= a[i].second) {
			cnt++;
			end = a[i].first;
			//cout << a[i].second << " " << a[i].first << "\n";
		}
	}
	cout << cnt;
}