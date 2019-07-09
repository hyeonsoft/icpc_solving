#include <iostream>
#include <vector>

using namespace std;

void doit(vector<int> &original, vector<vector<int>> originallist, int it) {
	if (original[it])return;
	original[it] = 1;
	for (int i = 0; i < originallist[it].size(); i++) {
		doit(original, originallist, originallist[it][i]);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	vector <int> com;
	vector <vector <int>> links;
	while (n--) {
		com.push_back(0);
		links.push_back(vector<int>{});
	}
	cin >> n;
	while (n--) {
		int u, t;
		cin >> u >> t;
		links[u-1].push_back(t-1);
		links[t - 1].push_back(u - 1);
	}
	doit(com, links, 0);
	int cnt = 0;
	for (int i = 1; i < com.size(); i++) {
		if (com[i])cnt++;
	}
	cout << cnt;
}