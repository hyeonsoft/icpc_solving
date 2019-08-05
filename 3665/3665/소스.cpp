#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int in[501]{ 0 };
	vector<vector<int>>line;
	vector<int>preset;
	for (int i = 0; i <= n; i++)line.push_back(vector<int>{});
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		preset.push_back(input);
	}
	for (int i = 0; i <= n-2; i++) {
		for (int p = i+1; p <= n-1; p++) {
			int a = preset[i], b = preset[p];
			in[b]++;
			line[a].push_back(b);
		}
	}
	line.size();
	int changed;
	cin >> changed;
	for (int i = 0; i < changed; i++) {
		int a, b;
		cin >> a >> b; //a의 원래 순위가 b보다 더 높다. 따라서 b의 순위가 더 높도록 바꿀 것.
		for (int i = 0; i < n; i++) {
			if (preset[i] == a)break;
			else if(preset[i] == b) {
				swap(a, b);
				break;
			}
		}
		auto it = find(line[a].begin(), line[a].end(), b);
		line[a].erase(it);
		line[b].push_back(a);
		in[b]--;
		in[a]++;
	}
	queue<int>list;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)list.push(i);
	}
	int check{ 0 };
	queue<int>ans;
	while (list.size()) {
		check++;
		int n = list.front();
		list.pop();
		ans.push(n);
		for (int i = 0; i < line[n].size(); i++) {
			in[line[n][i]]--;
			if (in[line[n][i]] == 0)list.push(line[n][i]);
		}
	}
	if (check == n) {
		while (ans.size()) {
			cout << ans.front() << " ";
			ans.pop();
		}
		cout << "\n";
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int testcase;
	cin >> testcase;
	while (testcase--)solve();
}