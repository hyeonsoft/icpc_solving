#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> nodes;
vector<int> depth;
queue<pair<int, int>>bfs_queue;


void get(int pos,int dep) {
	if (depth[pos] == dep)return;
	if (depth[pos] == -1||depth[pos]>dep) {
		depth[pos] = dep;
		for (int i = 0; i < nodes[pos].size(); i++) {
			bfs_queue.push(pair<int, int>(nodes[pos][i], dep + 1));
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		nodes.push_back(vector<int>{});
		depth.push_back(-1);
	}
	for (int i = 0; i < m; i++) {
		int t, v;
		cin >> t >> v;
		nodes[t].push_back(v);
		nodes[v].push_back(t);
	}
	bfs_queue.push(pair<int, int>(1, 0));

	while (bfs_queue.size()) {
		int a, b;
		a = bfs_queue.front().first;
		b = bfs_queue.front().second;
		bfs_queue.pop();
		get(a, b);
	}

	int maxdepth=0;
	int max = 0;
	int same = 1;

	for (int i = depth.size()-1; i >=1; i--) {
		//cout << i << " " << depth[i] << endl;
		if (depth[i] == -1)continue;
		if (maxdepth == depth[i]) {
			same++;
			max = i;
		}
		if (maxdepth < depth[i]) {
			maxdepth = depth[i];
			max = i;
			same = 1;
		}
	}

	cout << max << " " << maxdepth << " " << same;

}