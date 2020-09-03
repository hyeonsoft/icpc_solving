#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int x[4], y[4];
pair<int, int> vct[3];

int ccw(pair<int, int>v1, pair<int, int>v2) {
	int x=v1.first*v2.second - v1.second*v2.first;
	if (x > 0)return 1;
	else if (x == 0)return 0;
	else return -1;
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> x[i] >> y[i];
	}
	pair<int, int> i[3]{ {0,1},{1,2},{1,3} };
	for (int u = 0; u < 3;u++) {
		vct[u] = pair<int, int>{ x[i[u].second] - x[i[u].first], y[i[u].second] - y[i[u].first] };
	}
	if (ccw(vct[0], vct[1])*ccw(vct[0], vct[2]) < 0)cout << 1;
	else cout << 0;
}