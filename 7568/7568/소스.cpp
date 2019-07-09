//https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector < pair<int, int>> x;
	int ft;
	cin >> ft;
	for (int i = 0; i < ft; i++) {
		int a, b;
		cin >> a >> b;
		x.push_back({ a,b });
	}
	for (int i = 0; i < x.size(); i++) {
		int ans = 1;
		for (int p = 0; p < x.size(); p++) {
			if (x[i].first < x[p].first&&x[i].second < x[p].second)ans++;
		}
		cout << ans << " ";
	}
}