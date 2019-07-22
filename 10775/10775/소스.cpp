#include <iostream>
#include <string.h>

using namespace std;

char gates[100001];
int par[100001];
int find(int x) {
	if (par[x] == -1)return x;
	else {
		par[x] = find(par[x]);
		return par[x];
	}
}
int set(int x) {
	if (0 == gates[x]) {
		gates[x] = 1;
		par[x] = x - 1;
		return 1;
	}
	else {
		if (find(x) > 0) {
			gates[find(x)] = 1;
			par[find(x)] = find(x) - 1;
			return 1;
		}
		else {
			return 0;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	memset(par, -1, sizeof(par));
	int G, P;
	cin >> G >> P;
	int cnt = 0;
	int flag = 1;
	for (int i = 0; i < P; i++) {
		int g;
		cin >> g;
		if (!flag)continue;
		if (set(g)) {
			cnt++;
		}
		else {
			flag = 0;
		}
	}
	cout << cnt;
}