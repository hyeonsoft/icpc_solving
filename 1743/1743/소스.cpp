#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int x, y;
bool board[102][102];
bool check[102][102];

int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int dy[8] = { 1,-1,0,0,-1,-1,1,1 };

void go(int m, int n) {
	check[m][n] = 1;
	for (int i = 0; i < 8; i++) {
		if (!check[m + dx[i]][n + dy[i]] && board[m + dx[i]][n + dy[i]]) {
			go(m + dx[i], n + dy[i]);
		}
	}
}

int solve() {
	memset(board, 0, sizeof(board));
	memset(check, 0, sizeof(check));
	int ml=0;
	cin >> y;
	cin >> x;
	if (!x && !y)return 1;
	for (int i = 1; i <= x; i++) {
		for (int p = 1; p <= y; p++) {
			int temp;
			cin >> temp;
			board[i][p] = temp;
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int p = 1; p <= y; p++) {
			if (!check[i][p] && board[i][p]) {
				go(i, p);
				ml++;
			}
		}
	}
	cout << ml << "\n";
	return 0;
}

int main() {
	while (1) {
		if (solve() == 1)break;
	}
}