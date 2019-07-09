#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	map<pair<int,int>,int> layout;
	vector<pair<int, int>> pan;
	int n, l, m;
	cin >> n >> l >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		layout[pair<int,int>(x,y)] = 1;
		pan.push_back(pair<int, int>(x, y));
	}
	set<pair<int, int>> mylists;
	for (int i = 0; i < pan.size(); i++) {
		for (int p = 0; p < pan.size(); p++) {
			mylists.insert(pair<int, int>(pan[i].first, pan[p].second));
		}
	}
	int max = 0;
	auto it = mylists.begin();
	for(;it!=mylists.end();it++){
		int x = it->first;
		int y = it->second;

			for (int lx = 1; lx < l / 2; lx++) {
				int cnt = 0;
				if (lx + x >= n)break;
				int ly = l / 2 - lx;
				if (ly + y >= n || ly <= 0)break;
				for (int q = x; q < x + lx; q++) {
					for (int w = y; w < y + ly; w++) {
						if (layout[pair<int, int>(q, w)])cnt++;
					}
				}
				if (max < cnt)max = cnt;
			}

	}
	cout << max;
}