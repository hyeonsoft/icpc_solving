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
	vector<vector<int>>line;
	queue <int> q, ans;
	int in[1001]{ 0 };
	cin >> n >> m;
	for (int i = 0; i <= n; i++)line.push_back(vector<int>{});
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		vector<int>t;
		for (int j = 0; j < x; j++) {
			int nput;
			cin >> nput;
			t.push_back(nput);
		}
		for (int j = 0; j < t.size() - 1; j++) {
			int a, b;
			a = t[j], b = t[j + 1];
			in[b]++;
			line[a].push_back(b);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)q.push(i);
	}
	int is_circle = 0;
	int checked{ 0 };
	while (q.size()) {
		checked++;
		int n = q.front();
		q.pop();
		ans.push(n);
		for (int i = 0; i < line[n].size(); i++) {
			in[line[n][i]]--;
			if (in[line[n][i]] == 0)q.push(line[n][i]);
		}
	}
	is_circle = checked == n;
	if (!is_circle) {
		cout << 0;
	}
	else {
		while (ans.size()) {
			cout << ans.front() << "\n";
			ans.pop();
		}
	}
}