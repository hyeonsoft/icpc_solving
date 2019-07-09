#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> bfsq;
int check[200001]{ 0 };
int s, e;

int solv = 0;

void go(int n,int d) {
	if (n == e) {
		solv = d;
		return;
	}
	if (check[n])return;
	check[n] = 1;
	bfsq.push(pair<int, int>(n + 1, d + 1));
	if (n == 0) {
		return;
	}
	bfsq.push(pair<int, int>(n - 1, d + 1));
	if (n > e) {
		return;
	}
	bfsq.push(pair<int, int>(n * 2, d + 1));
}

int main() {
	cin >> s >> e;
	bfsq.push(pair<int, int>(s, 0));
	while (bfsq.size()&&(!solv)) {
		int now, depth;
		now=bfsq.front().first;
		depth=bfsq.front().second;
		bfsq.pop();
		go(now,depth);
	}
	cout << solv;
}