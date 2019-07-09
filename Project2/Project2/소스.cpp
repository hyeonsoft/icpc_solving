#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int N;
int main() {
	map<int, map<int, int>> fluid{};
	cin >> N;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (a == b)continue;
			fluid[a][b] = INF;
		}
	}
	for (;;) {
		int a, k;
		cin >> a >> k;
		if (a == -1 && k == -1)break;
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
	int sum[50]{ 0 };
	int min = INF;
	auto a = vector<int>{};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i] = max(sum[i], fluid[i][j]);
		}
		if (sum[i] == min)a.push_back(i);
		else if (sum[i] < min) {
			a = vector<int>{};
			a.push_back(i);
			min = sum[i];
		}
	}
	cout << min << " " << a.size() << "\n";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}