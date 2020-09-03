#include <iostream>
#include <vector>
using namespace std;
int honeycomb[15][40];
bool isgroup[15][40]{ 0 };

int t, f;
pair<int, int> go1(int i, int j) {
	return pair<int, int>{i, j - 2};
}
pair<int, int> go2(int i, int j) {
	return pair<int, int>{i, j + 2};
}
pair<int, int> go3(int i, int j) {
	return pair<int, int>{i+1, j - 1};
}
pair<int, int> go4(int i, int j) {
	return pair<int, int>{i-1, j - 1};
}
pair<int, int> go5(int i, int j) {
	return pair<int, int>{i+1, j + 1};
}
pair<int, int> go6(int i, int j) {
	return pair<int, int>{i-1, j + 1};
}

int main() {
	cin >> t >> f;
	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j <= 40; j++) {
			honeycomb[i][j] = -2147483648;
		}
	}
	for (int i = 1; i <= 2 * t - 1; i++) {
		int blank = t - i; blank = abs(blank);
		for (int j = 1 + blank; j <= 4*t-3-blank; j += 2) {
			cin >> honeycomb[i][j];
		}
	}
	//벌집의 + 에너지끼리, -에너지끼리 그룹을 짓는다.
	for (int i = 1; i <= 2 * t - 1; i++) {
		int blank = t - i; blank = abs(blank);
		for (int j = 1 + blank; j <= 4 * t - 3 - blank; j += 2) {
			cin >> honeycomb[i][j];
		}
	}
	//각 + 그룹마다 완전탐색을 통해서 최대 얻을 수 있는 에너지량을 구한다.
	//에너지를 구할 때 필요한 검색량을 줄이기 위해서 비용이 해당 블럭을 얻을 때 얻는 이득보다 적으면 버린다.
}