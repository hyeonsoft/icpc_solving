#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
	int n, k, w;
	cin >> n >> k;
	vector<vector<int>> line;
	int d[1001]{ 0 };
	int in[1001]{ 0 };
	queue<int> temp;
	queue<int> b;
	line.push_back(vector<int>{});
	for (int i = 1; i <= n; i++) {
		line.push_back(vector<int>{});
		int t;
		cin >> t;
		d[i] = t;
	}
	while (k--) {
		int a, b;
		cin >> a >> b;
		in[b]++;
		line[a].push_back(b);
	}
	int takingtime[1001]{ 0 };
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			temp.push(i);
			takingtime[i] = d[i];
		}
	}
	while (temp.size()) {
		int f = temp.front();
		temp.pop();
		for (int i = 0; i < line[f].size(); i++) {
			takingtime[line[f][i]] = max(takingtime[line[f][i]], takingtime[f] + d[line[f][i]]);
			in[line[f][i]]--;
			if(in[line[f][i]]==0)temp.push(line[f][i]);
		}
	}
	cin >> w;
/*	for (int i = 1; i <= n; i++) {
		cout << endl << takingtime[i] << " " << in[i] << " " << d[i];
	}
	cout << endl;*/
	cout << takingtime[w] << "\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}