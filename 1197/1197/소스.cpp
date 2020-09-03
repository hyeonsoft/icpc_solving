#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, pair<int, int>>> line;
int v, e;

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		line.push_back(pair<int, pair<int, int>>{c, pair<int, int>{a, b}});
	}
	sort(line.begin(), line.end());
}