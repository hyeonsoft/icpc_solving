#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;

map<int, map<int, int>>fluid;

int N, M; //vortex, lines

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			fluid[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		fluid[a][b] = c;
		fluid[b][a] = c;
	}
	int J, S;
	cin >> J >> S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				fluid[i][k] = min(fluid[i][j] + fluid[j][k], fluid[i][k]);
			}
		}
	}
	map<int, int> dist;
	vector<int> a;
	int min = INF;
	int num = -1;
	for (int i = 1; i <= N; i++) {
		if (fluid[i][J] < fluid[i][S]||i==J||i==S) {
			continue;
		}
		dist[i] = fluid[i][J] + fluid[i][S];
		if (dist[i] < min) {
			a.clear();
			a.push_back(i);
			min = dist[i];
		}
		else if (dist[i] == min) {
			a.push_back(i);
		}
	}
	min = INF;
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << dist[a[i]]<<fluid[J][a[i]]<< endl;
		if (min > fluid[J][a[i]]) {
			num = a[i];
			min = fluid[J][a[i]];
		}
	}
	cout << num;
}