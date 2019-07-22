#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int subjget() {
	int p, l;
	cin >> p >> l;
	vector<int>a;
	while (p--) {
		int k;
		cin >> k;
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	if (a.size() < l)return 1;
	return a[a.size()-l];
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>mil;
	while (n--) {
		int x = subjget();
	//	cout << x << endl;
		mil.push_back(x);
	}
	sort(mil.begin(), mil.end());
	int cnt = 0;
	int used = 0;
	for (int i = 0; i < mil.size(); i++) {
		used += mil[i];
		if (used > m)break;
		cnt++;
	}
	cout << cnt;
}