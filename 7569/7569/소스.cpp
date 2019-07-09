#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int tomato[101][101][101]{ 0 };
queue<int> BfsQueue[4];
int check[101][101][101]{ 0 };
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,1,-1,0,0 };
int m, n, h;

void bfs() {
	while (BfsQueue[0].size()) {
		int x = BfsQueue[0].front(), y = BfsQueue[1].front(), z = BfsQueue[2].front(), floor = BfsQueue[3].front();
		for (int i = 0; i < 4; i++) {
			BfsQueue[i].pop();
		}
		if (check[x][y][z]==-1&&check[x][y][z]<floor) {
			check[x][y][z] = floor;
			for (int i = 0; i < 6; i++) {
				int q = x + dx[i];
				int w = y + dy[i];
				int e = z + dz[i];
				if (q != 0 && w != 0 && e != 0 && m >= q && n >= w && h >= e&&tomato[q][w][e]!=-1) {
					BfsQueue[0].push(q);
					BfsQueue[1].push(w);
					BfsQueue[2].push(e);
					BfsQueue[3].push(floor+1);
				}
			}
		}
	}
}

int main() {
	memset(check, -1, sizeof(check));
	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++) {
		for (int p = 1; p <= n; p++) {
			for (int o = 1; o <= m; o++) {
				int temp;
				cin >> temp;
				tomato[o][p][i] = temp;
				if (temp == 1) {
					BfsQueue[0].push( o);
					BfsQueue[1].push(p);
					BfsQueue[2].push(i);
					BfsQueue[3].push(0);
				}
			}
		}
	}
	bfs();
	int max = -1;
	for (int i = 1; i <= h; i++) {
		for (int p = 1; p <= n; p++) {
			for (int o = 1; o <= m; o++) {
				if(tomato[o][p][i]!=-1){
					if (check[o][p][i] == -1) {
						max = -1;
						o = m; p = n; i = h;
						break;
					}
					if (check[o][p][i] > max)max = check[o][p][i];
				}
			}
		}
	}
	cout << max;
}