#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<long long int, long long int> P;
typedef pair<long long int, long long int> V;

int ccw(V v1, V v2) {
	long long int x = v1.first*v2.second - v2.first*v1.second;
	if (x > 0)return 1;
	else if (x < 0) return -1;
	else return 0;
}
P operator-(P a, P b) {
	return P{ a.first - b.first, a.second - b.second };
}
int is_cross(P a, P b, P c, P d) {
	V v1{ b - a };
	V v2{ c - a };
	V v3{ d - a };
	V v11{ a - c };
	V v12{ b - c };
	V v13{ d - c };
	int f=ccw(v1, v2)* ccw(v1, v3);
	int s = ccw(v13, v11)*ccw(v13, v12);
	if (f == 0 && s == 0) {
		return -1;
	}
	else return f<=0 && s<=0;
}
void testcase() {
	long long int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	P line[2];
	line[0] = P{ a, b };
	line[1] = P{ c, d };
	int left = min(e, g);
	int right = max(e, g);
	int top = max(f, h);
	int bottom = min(f, h);
	P boxs[5]{ {left, top},{right, top}, {right, bottom}, {left, bottom}, {left, top} };
	if (left <= a && a <= right && left <= c && c <= right && bottom <= b && b <= top && bottom <= d && d <= top) {
		cout << "T\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x = is_cross(line[0], line[1], boxs[i], boxs[i + 1]);
		if (x == -1) {
			if (line[0].first - line[1].first == 0) {
				int q = min(line[0].second, line[1].second);
				int w = max(line[0].second, line[1].second);
				if (w >= bottom && q <= top) {
					cout << "T\n";
					return;
				}
			}
			else {
				int q = min(line[0].first, line[1].first);
				int w = max(line[0].first, line[1].first);
				if (w >= left && q <= right) {
					cout << "T\n";
					return;
				}
			}
		}
		else if (x == 1) {
			cout << "T\n";
			return;
		}
	}
	cout << "F\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		testcase();
	}

}