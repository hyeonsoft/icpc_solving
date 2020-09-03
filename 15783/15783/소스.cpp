#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;


vector<vector<int>>line;
vector<vector<int>>from;
stack<int>visits;
int is_visited[100001]{ 0 };
int is_included[100001];
vector<vector<int>>scc;
int cnt;
int ans;

int dfs(int v) {
	visits.push(v);
	int min = is_visited[v] = ++cnt;
	for (auto x : line[v]) {
		if (is_visited[x] == 0)min=::min(dfs(x), min);
		else if (is_included[x] == -1)min = ::min(min, is_visited[x]);
	}
	if (min == is_visited[v]) {
		ans++;
		scc.push_back(vector<int>{});
		while (1) {
			int top = visits.top();
			is_included[top] = scc.size()-1;
			visits.pop();
			scc[scc.size() - 1].push_back(top);
			if (top == v)break;
		}
	}
	return min;
}

vector<set<int>>scc_from;
vector<set<int>>scc_to;



void scc_construct() {
	for (int i = 0; i < scc.size(); i++) {
		scc_from.push_back(set<int>{});
		scc_to.push_back(set<int>{});
	}
	for (int i = 0; i < scc.size(); i++) {
		for (int p = 0; p < scc[i].size(); p++) {
			for (auto l : line[scc[i][p]]) {
				if (i == is_included[l])continue;
				scc_to[i].insert(is_included[l]);
			}
			for (auto l : from[scc[i][p]]) {
				if (i == is_included[l])continue;
				scc_from[i].insert(is_included[l]);
			}
		}
	}
}

int scc_visited[100001]{ 0 };
int ans_cnt;


void findhead(int scc_idx) {
	if (scc_visited[scc_idx] != 0)return;
	scc_visited[scc_idx] = 1;
	if (scc_from[scc_idx].size() == 0)ans_cnt++;
	else for (auto i : scc_from[scc_idx]) {
		findhead(i);
	}
	for (auto i : scc_to[scc_idx]) {
		findhead(i);
	}
}

int main() {
	memset(is_included, -1, sizeof(is_included));
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		line.push_back(vector<int>{});
		from.push_back(vector<int>{});
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		from[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (is_visited[i] == 0)dfs(i);
	}
	scc_construct();
	for (int i = 0; i < scc.size(); i++) {
		findhead(i);
	}
	cout << ans_cnt;
}