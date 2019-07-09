#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int tomato[1001][1001]{ 0 };
queue<int> BfsQueue[3];
int check[1001][1001]{ 0 };
int dx[6] = { 1,-1,0,0 };
int dy[6] = { 0,0,1,-1 };
int m, n;

void bfs() {
	while (BfsQueue[0].size()) {
		int x = BfsQueue[0].front(), y = BfsQueue[1].front(), floor = BfsQueue[2].front();
		for (int i = 0; i < 3; i++) {
			BfsQueue[i].pop();
		}
		if (check[x][y] == -1 && check[x][y] < floor) {
			check[x][y] = floor;
			for (int i = 0; i < 4; i++) {
				int q = x + dx[i];
				int w = y + dy[i];
				if (q != 0 && w != 0 &&  m >= q && n >= w&& tomato[q][w] != -1) {
					BfsQueue[0].push(q);
					BfsQueue[1].push(w);
					BfsQueue[2].push(floor + 1);
				}
			}
		}
	}
}

int main() {
	memset(check, -1, sizeof(check));
	cin >> m >> n;
//	for (int i = 1; i <= h; i++) {
		for (int p = 1; p <= n; p++) {
			for (int o = 1; o <= m; o++) {
				int temp;
				cin >> temp;
				tomato[o][p] = temp;
				if (temp == 1) {
					BfsQueue[0].push(o);
					BfsQueue[1].push(p);
					BfsQueue[2].push(0);
				}
			}
		}
//	}
	bfs();
	int max = -1;
//	for (int i = 1; i <= h; i++) {
		for (int p = 1; p <= n; p++) {
			for (int o = 1; o <= m; o++) {
				if (tomato[o][p] != -1) {
					if (check[o][p] == -1) {
						max = -1;
						o = m; p = n;
						break;
					}
					if (check[o][p] > max)max = check[o][p];
				}
			}
		}
//	}
	cout << max;
}