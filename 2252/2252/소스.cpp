#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	queue<int> a;
	queue<int> b;
	vector<vector<int>> line;
	n++;
	int in[32001]{ 0 };
	while (n--)line.push_back(vector<int>{});
	while (m--) {
		int a, b;
		cin >> a >> b;
		in[b]++;
		line[a].push_back(b);
	}
	for (int i = 1; i < line.size(); i++) {
		if (in[i] == 0)a.push(i);
	}
	
	while (a.size()) {
		int n = a.front();
		a.pop();
		b.push(n);
		for (int i = 0; i < line[n].size(); i++) {
			in[line[n][i]]--;
			if (in[line[n][i]] == 0)a.push(line[n][i]);
		}
	}

	while (b.size()) {
		cout << b.front() << " ";
		b.pop();
	}
}