#include <iostream>
#include <string.h>
using namespace std;

int par[201];

int find(int x) {
	if (par[x] == -1) {
		return x;
	}
	else {
		par[x] = find(par[x]);
		return par[x];
	}
}

void merge(int a, int b) {
	int x, y;
	x = find(a);
	y = find(b);
	if (x == y)return;
	par[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(par, -1, sizeof(par));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= n; p++) {
			int k;
			cin >> k;
			if (k)merge(i, p);
		}
	}
	int k;
	int flag = 1;
	cin >> k;
	int f = find(k);
	for (int i = 1; i < m; i++) {
		cin >> k;
		flag *= (find(k) == f);
	}
	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}