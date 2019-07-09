#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> graph;
vector<int> check;

void dfs(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		if (check[graph[x][i]] == 0) {
			check[graph[x][i]] = 1;
			dfs(graph[x][i]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		graph.push_back(vector<int>{});
		check.push_back(0);
	}
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= n; p++) {
			int temp;
			cin >> temp;
			if (temp) {
				graph[i].push_back(p);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= n; p++) {
			check[p] = 0;
		}
		dfs(i);
		for (int p = 1; p <= n; p++) {
			cout << check[p] << " ";
		}
		cout << "\n";
	}
}