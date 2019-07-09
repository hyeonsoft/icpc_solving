#include <iostream>
#include <set>

using namespace std;

int pan[5][5];
set<int> lists;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int y, int x, int d, int a) {
	if (d == 5) {
		lists.insert(a * 10 + pan[y][x]);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int xp = dx[i] + x;
		int yp = dy[i] + y;
		if (xp == 5 || yp == 5 || xp < 0 || yp < 0) {
			continue;
		}
		else {
			dfs(yp, xp, d + 1, a * 10 + pan[y][x]);
		}
	}
}


int main() {
	for (int i = 0; i < 5; i++) {
		for (int p = 0; p < 5; p++) {
			cin >> pan[i][p];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int p = 0; p < 5; p++) {
			dfs(i, p, 0, 0);
		}
	}
	cout << lists.size();
}