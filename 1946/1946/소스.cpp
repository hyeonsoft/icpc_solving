#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}

void testcase() {
	vector<pair<int, int>>t;
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		t.push_back(pair<int, int>(a, b));
	}
	sort(t.begin(), t.end(), cmp);
	int i = 0, j = 1, cnt=0;
	while (j < t.size()) {
		if (t[j].second < t[i].second) {
			i = j;
			cnt++;
		}
		j++;
	}
	cout << cnt+1 << "\n";
}

int main() {
	int tests;
	cin >> tests;
	while (tests--)testcase();
}