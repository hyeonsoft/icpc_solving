#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

stack<int>found;
int cnt{ 0 };
int visited[100001]{ 0 };
int scced[100001]{ 0 };
vector<vector<int>>line;
vector<vector<int>>scc;
int dfs(int next) {
	//	if (visited[next] != 0)return visited[next];
	int min = visited[next] = ++cnt;
	found.push(next);
	for (auto i : line[next]) {
		if (visited[i] == 0)min = ::min(min, dfs(i));
		else if (scced[i] == 0)min = ::min(min, visited[i]);
	}
	if (min == visited[next]) {
		scc.push_back(vector<int>{});
		while (1) {
			int top = found.top();
			scc[scc.size() - 1].push_back(top);
			found.pop();
			scced[top] = 1;
			if (top == next)break;
		}
		sort(scc[scc.size() - 1].begin(), scc[scc.size() - 1].end());
	}
	return min;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i <= v; i++) {
		line.push_back(vector<int>{});
	}
	for (int i = 0; i < e; i++) {
		int q, w;
		cin >> q >> w;
		line[q].push_back(w);
	}
	for (int i = 1; i <= v; i++) {
		if (visited[i] == 0)dfs(i);
	}
	sort(scc.begin(), scc.end());
	cout << scc.size() << "\n";
	for (auto i : scc) {
		for (auto x : i) {
			cout << x << " ";
		}
		cout << "-1\n";
	}
}