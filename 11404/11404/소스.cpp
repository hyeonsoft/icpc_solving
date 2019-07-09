#include <iostream>
#include <map>
#include <algorithm>
#define INF 40000000000000

using namespace std;

int n, m;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	long long int dist[101][101];
	cin >> n>>m;
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b) {
				dist[a][b] = 0;
				continue;
			}
			dist[a][b] = INF;
		}
	}
	for (int i = 0; i < m ; i++) {
		int a, b;
		long long int c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b],c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (dist[i][j]>=INF?0:dist[i][j]) << " ";
		}
		cout << "\n";
	}
}