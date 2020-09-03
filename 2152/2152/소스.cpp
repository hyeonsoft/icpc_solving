#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, s, t;

vector<vector<int>>to;


int main() {
	cin >> n >> m >> s >> t;
	for (int i = 0; i <= n; i++) {
		to.push_back(vector<int>{});
	}
	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;
		to[q].push_back(w);
	}
}