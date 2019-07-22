#include <iostream>
#include <string.h>
using namespace std;

int par[1000001];

int find(int x) {
	if (par[x] == -1) {
		return x;
	}
	else {
		par[x]=find(par[x]);
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
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) { //합집합
			merge(b, c);
		}
		else { //확인작업
			if (find(b) == find(c)) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
}