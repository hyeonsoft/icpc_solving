#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string a, b;
int dp[1000][1000];

int solve(int x, int y) {
	if (x >= a.size() || y >= b.size()) {
		return 0;
	}
	if (dp[x][y] != -1)return dp[x][y];
	int &reg = dp[x][y];
	if (a[x] == b[y]) {
		return reg = 1 + solve(x + 1, y + 1);
	}
	else {
		return reg = max(solve(x + 1, y), solve(x, y + 1));
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	cout << solve(0, 0);
}