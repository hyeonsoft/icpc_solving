#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t[10000][3];
int n;
int x[10000];

int get(int l, int cnt) {
	if (cnt >= 3) {
		return -9999999;
	}
	if (l == n) {
		return 0;
	}
	if (t[l][cnt] != -1) {
		return t[l][cnt];
	}
	t[l][cnt] = max((get(l + 1, cnt + 1) + x[l]), get(l + 1, 0));
	return t[l][cnt];
}

int main() {
	cin >> n;
	int i = n;
	while (i--) {
		cin >> x[i];
	}
	memset(t, -1, sizeof(t));
	cout << get(0,0);
}