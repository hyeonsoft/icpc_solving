#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	int d[501]{ 0 };
	int in[501]{ 0 };
	vector<vector<int>>line;
	cin >> n;
	for (int i = 0; i <= n; i++)line.push_back(vector<int>{});
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		while (1) {
			int input;
			cin >> input;
			if (input == -1)break;
			else {
				line[input].push_back(i);
				in[i]++;
			}
		}
	}
	queue<int>waiting_list;
	int takingtime[501]{ 0 };
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)waiting_list.push(i);
		takingtime[i] = d[i];
	}
	while (waiting_list.size()) {
		int n = waiting_list.front();
		waiting_list.pop();
		for (int i = 0; i < line[n].size(); i++) {
			takingtime[line[n][i]] = max(takingtime[line[n][i]], takingtime[n] + d[line[n][i]]);
			in[line[n][i]]--;
			if (in[line[n][i]] == 0)waiting_list.push(line[n][i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << takingtime[i] << "\n";
	}
}