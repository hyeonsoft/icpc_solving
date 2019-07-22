#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>>grid;

int r, c, ans;
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

bool road(int y, int x) {
	if (x == r - 1) {
		ans++;
		return 1;
	}

	grid[y][x] = 2;
	for (int i = 0; i < 8; i++) {
		if (!grid[y + dy[i]][x + dx[i]]) {
			y += dy[i]; x += dx[i];
			if (road(y, x))return 1;
		}
	}
	return 0;
}

int main() {
	int x;
	cin >> r >> c;
	x = c+2;
	while (x--)grid.push_back(vector<char>{});
	for (int i = 1; i <= c; i++) {
		for (int p = 0; p < r; p++) {
			char x;
			cin >> x;
			if (x == '.')x = 0;
			else x = 1;
			grid[i].push_back(x);
		}
	}
	for (int i = 0; i < r; i++) {
		grid[0].push_back(1);
		grid[c + 1].push_back(1);
	}
	for (int i = 1; i <= c; i++) {
		road(i, 0);
	}
	cout << ans;
}