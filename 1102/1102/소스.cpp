#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int N, P;
int price[17][17];
int dpprice[1 << 17];
int getNumbersOfOnstate(int state) {
	int ret=0;
	while (state != 0) {
		ret += state % 2;
		state /= 2;
	}
	return ret;
}
int dp(int currentState) {
	if (getNumbersOfOnstate(currentState)>=P) {
		return 0;
	}
	int &reg = dpprice[currentState];
	if ( reg != -1)return reg;
	reg = 987654321;
	for (int i = 1; i <= N; i++) {
		if ((currentState&(1 << (i - 1))) !=0)continue;
		int minprice = 987654321;
		for (int p = 1; p <= N; p++) {
			if(currentState&(1<<(p-1)))
			minprice = min(minprice, price[p][i]);
		}
		if (minprice == 987654321)continue;
		reg = min(reg, dp(currentState|(1<<(i-1)))+minprice);
	}
	return reg;
}
int main() {
	memset(dpprice, -1, sizeof(dpprice));
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int p = 1; p <= N; p++) {
			cin >> price[i][p];
		}
	}
	string state;
	cin >> state;
	cin >> P;
	int initialstate=0;
	for (int i = 1; i <= N; i++) {
		if (state[i - 1] == 'Y')initialstate |= 1 << (i - 1);
	}
	int t = dp(initialstate);
	if (t >= 987654321)cout << -1;
	else cout << t;
}