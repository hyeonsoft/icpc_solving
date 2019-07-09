#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int N, M;
int main() {
	map<int, map<int, int>> fluid{};
	cin >> N >> M;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (a == b)continue;
			fluid[a][b] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, k;
		cin >> a >> k;
		fluid[a][k] = 1;
		fluid[k][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				fluid[i][j] = min(fluid[i][j], fluid[i][k] + fluid[k][j]);
			}
		}
	}
	int sum[101]{ 0 };
	int min = INF;
	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i] += fluid[i][j];
		}
		if (sum[i] < min) {
			num = i;
			min = sum[i];
		}
	}
	cout << num;
}