#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ns, k, minval;
int val[101];
int dp[10001];

int sol(int n) {
	if (n == 0)return 0;
	if (n < 0)return 987654321;
	if (dp[n] != -1)return dp[n];
	int &ref = dp[n];
	int min = 987654321;
	for (int i = 0; i < ns; i++) {
		int x = sol(n - val[i]);
		min = x<min?x:min;
	}
	return ref = min+1;
}

int main() {
	cin >> ns>>k;
	minval = 999999;
	memset(dp, -1, sizeof(dp));
	for (int a=0; a < ns; a++) {
		int t;
		cin >> t;
		val[a] = t;
		if (t < minval)minval = t;
	}
	cout << sol(k);
}