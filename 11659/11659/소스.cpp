#include <iostream>

using namespace std;

int n;
int m;
int num[100001];
int psum[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	psum[0] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		num[i] = t;
		psum[i] = psum[i - 1] + t;
	}
	while (m--) {
		int s, e, sum=0;
		cin >> s >> e;
		cout << psum[e] - psum[s-1]<<"\n";
	}
}