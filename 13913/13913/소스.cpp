#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int is_checked[100001]{ 0 };
int s, e;

queue<pair<vector<int>, int>> dfs; //pair<지금까지 지나온 수, number>

void dfsplus() {

	dfs.push(pair<vector<int>, int>(startpos, s - 1));
}

int main() {
	cin >> s >> e;
	vector<int> startpos;
	startpos.push_back(s);
}