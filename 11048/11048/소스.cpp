#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001][1001];
int m, n;
int candy[1001][1001] = { 0 };

int get(int PosX, int PosY) {
	if (PosX < 0 || PosY < 0)return 0;
	if (dp[PosX][PosY] != -1)return dp[PosX][PosY];
	int &reg = dp[PosX][PosY];
	return reg = candy[PosX][PosY] + max(get(PosX - 1, PosY), get(PosX, PosY - 1));
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int o = 0; o < n; o++) {
		for (int p = 0; p < m; p++) {
			int x;
			cin >> x;
			candy[o][p] = x;
		}
	}
	cout<<get(n-1,m-1);
}