#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int x, y, m;
bool board[52][52];
bool check[52][52];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void go(int m, int n) {
	check[m][n] = 1;
	for (int i = 0; i < 4; i++) {
		if (!check[m + dx[i]][n + dy[i]]&&board[m + dx[i]][n + dy[i]]) {
			go(m + dx[i], n + dy[i]);
		}
	}
}

void solve() {
	m = 0;
	memset(board, 0, sizeof(board));
	memset(check, 0, sizeof(check));
	int t;
	cin >> x >> y >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		board[m+1][n+1] = 1;
	}
	for (int i = 1; i <= x; i++) {
		for (int p = 1; p <= y; p++) {
			if (!check[i][p]&&board[i][p]) {
				go(i, p);
				m++;
			}
		}
	}
	cout << m << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}