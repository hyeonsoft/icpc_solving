#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	priority_queue <int>pq;
	queue<int> ans;
	int in[32001]{ 0 };
	cin >> n >> m;
	vector<vector<int>>line;
	for (int i = 0; i <= n; i++) {
		line.push_back(vector<int>{});
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		in[b]++;
		line[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)pq.push(-i);
	}
	while (pq.size()) {
		int n = -pq.top();
		ans.push(n);
		pq.pop();
		for (int i = 0; i < line[n].size(); i++) {
			in[line[n][i]]--;
			if (in[line[n][i]] == 0)pq.push(-line[n][i]);
		}
	}
	while (ans.size()) {
		cout << ans.front()<<" ";
		ans.pop();
	}
}