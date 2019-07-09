#include <iostream>
#include <queue>
using namespace std;
int e;
bool notprime[4000001]{ 0 };
int primes[300000];
int made{ 1 };
int primemake(int m) {
	if (m > made) {
		made = m;
		for (int i = 2; i <= m; i++) {
			if (!notprime[i]) {
				for (int u = 2; u*i <= m; u++) {
					notprime[u*i] = 1;
				}
			}
		}
	}
	return -1;
}
queue<pair<int, int>> bfsq; //value, depth
bool check[10000]{ 0 };
int flag{ 0 };
void is_okay(int n, int depth) {
	if (!notprime[n]) {
		bfsq.push(pair<int, int>(n, depth + 1));
		if (e == n)flag = depth + 1;
	}
}
void bfs() {
	while (bfsq.size()&&!flag) {
		int n = bfsq.front().first;
		int nd = bfsq.front().second;
		bfsq.pop();
		if (check[n])continue;
		check[n] = 1;
		int d = n % 10;
		int c = (n /= 10) % 10;
		int b = (n /= 10) % 10;
		int a = (n /= 10);
		//천의자리
		for (int i = 1; i <= 9;i++) {
			is_okay(i * 1000 + n % 1000, nd);
		}
		//백의자리
		for (int i = 0; i <= 9; i++) {
			is_okay(a * 1000 + i * 100 + c * 10 + d, nd);
		}
		for (int i = 0; i <= 9; i++) {
			is_okay(a * 1000 + b * 100 + i * 10 + d, nd);
		}
		for (int i = 0; i <= 9; i++) {
			is_okay(a * 1000 + b * 100 + c * 10 + i, nd);
		}
	}
}
int main() {
	notprime[1] = 1;
	primemake(9999);
	int s;
	cin >> s >> e;
	bfsq.push(pair<int, int>(s, 0));
	bfs();
	if(flag)cout << flag;
	else cout << "Impossible";
	cout << "\n";
}