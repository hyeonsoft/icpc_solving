#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int,int>> BFS_queue; //first : 정점, second : 하위 단계
vector<vector<int>> nodes;
vector<int> dist;

int BFS(int &find) {
	while (BFS_queue.size()) {
		auto a = BFS_queue.front();
		BFS_queue.pop();
		for (int i = 0; i < nodes[a.first].size(); i++) {
			if (nodes[a.first][i] == find) {
				return a.second + 1;
			}
			if (dist[nodes[a.first][i]] == -1) {
				dist[nodes[a.first][i]] = a.second + 1;
				BFS_queue.push(pair<int, int>(nodes[a.first][i], a.second + 1));
			}
		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		nodes.push_back(vector<int>{});
		dist.push_back(-1);
	}
	int a, b;
	cin >> a >> b;
	int t;
	cin >> t;
	while (t--) {
		int u, x;
		cin >> u >> x;
		nodes[u].push_back(x);
		nodes[x].push_back(u);
	}
	BFS_queue.push(pair<int, int>(a, 0));
	dist[b] = 0;
	cout<<BFS(b);
}