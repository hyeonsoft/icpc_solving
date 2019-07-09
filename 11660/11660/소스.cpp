#include <iostream>

using namespace std;

int pa[1025][1025];
int psum[1025][1025]{ 0 };

int n, t;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= n; p++) {
			int val;
			cin >> val;
			pa[i][p] = val;
			psum[i][p] = val + psum[i - 1][p] + psum[i][p - 1] - psum[i - 1][p - 1];
		}
	}
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << psum[d][c] - psum[b-1][a-1] << "\n";
	}
}