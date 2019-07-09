#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int x, y, ml;
int board[102][102];
int check[102][102];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int nx,int ny) {
	ml++;
	for (int i = 0; i < 4; i++) {
		if (2==board[nx + dx[i]][ny + dy[i]] && !check[nx + dx[i]][ny + dy[i]]) {
			check[nx + dx[i]][ny + dy[i]] = 1;
			dfs(nx + dx[i],ny + dy[i]);
		}
	}
}

int main() {
	vector<int> lists;
	memset(board, 0, sizeof(board));
	memset(check, 0, sizeof(check));
	int t;
	cin >> x>>y>>t;
	for (int i = 1; i <= x; i++) {
		for (int p = 1; p <= y; p++) {
			board[i][p] = 2;
		}
	}
	while (t--) {
		int xs, ys, xe, ye;
		cin >> xs >> ys >> xe >> ye;
		for (int i = xs + 1; i <= xe; i++) {
			for (int p = ys + 1; p <= ye; p++) {
				board[i][p] = 1;
			}
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int p = 1; p <= y; p++) {
			if (!check[i][p] && 2==board[i][p]) {
				ml = 0;
				dfs(i, p);
				lists.push_back(ml);
			}
		}
	}
	sort(lists.begin(), lists.end()); board; check;
	cout << lists.size() << "\n";
	for (int i = 0; i < lists.size(); i++) {
		cout << lists[i] << " ";
	}
}