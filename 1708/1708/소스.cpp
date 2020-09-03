#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

typedef long long int ll;

vector<pair<int, int>> point;
int up[100001];
int down[100001];
int ut{ 0 }, dt{ 0 };

pair<int, int> operator-(pair<int, int>A, pair<int, int>B) {
	return pair<int, int>{A.first - B.first, A.second - B.second};
}

ll ccw(pair<int, int>A, pair<int, int>B) {
	return (ll)A.first*B.second - (ll)A.second*B.first;
}

int ccw_by_point(pair<int, int>A, pair<int, int>B, pair<int, int>C) {
	ll a = ccw(B - A, C - B);
	if (a > 0)return 1; //시계 반대방향
	if (a == 0)return 0; //평행
	if (a < 0)return -1; //시계방향
}

int main() {
	int a;
	cin >> a;
	while (a--) {
		int b, c;
		cin >> b >> c;
		point.push_back(pair<int, int>{b, c});
	}
	sort(point.begin(), point.end());

	ut = 0;
	for (int i = 0; i < point.size(); i++) {
		while (ut >= 2 && ccw_by_point(point[up[ut - 2]], point[up[ut - 1]], point[i])>=0) {
			ut--;
		}
		up[ut++] = i;
	}
	dt = 0;
	for (int i = point.size()-1; i >= 0; i--) {
		while (dt >= 2 && ccw_by_point(point[down[dt - 2]], point[down[dt - 1]], point[i])>=0) {
			dt--;
		}
		down[dt++] = i;
	}
	cout << ut + dt-2;
}