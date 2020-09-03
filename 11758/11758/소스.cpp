#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int x[3];
int y[3];
pair<int, int> vct[2];
int ccw(pair<int, int>v1, pair<int, int>v2) {
	return v1.first*v2.second - v1.second*v2.first;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	vct[0] = pair<int, int>{ x[1] - x[0], y[1] - y[0] };
	vct[1] = pair<int, int>{ x[2] - x[1], y[2] - y[1] };
	int a = ccw(vct[0], vct[1]);
	if (a == 0) {
		cout << 0;
	}
	else if (a > 0) {
		cout << 1;
	}
	else {
		cout << -1;
	}
}