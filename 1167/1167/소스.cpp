#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>nodes;
vector<vector<int>>length;
vector<int>depth1;
vector<int>depth2;
queue<pair<int, int>>bfsq;

void go1(pair<int,int> x) {
	int current = x.first;
	int depth = x.second;
	if (depth1[current] == -1) {
		depth1[current] = depth;
		for (int i = 0; i < nodes[current].size(); i++) {
			bfsq.push(pair<int, int>(nodes[current][i], depth + length[current][i]));
		}
	}
}

void go2(pair<int, int> x) {
	int current = x.first;
	int depth = x.second;
	if (depth2[current] == -1) {
		depth2[current] = depth;
		for (int i = 0; i < nodes[current].size(); i++) {
			bfsq.push(pair<int, int>(nodes[current][i], depth + length[current][i]));
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i <= t; i++) {
		nodes.push_back(vector<int>{});
		length.push_back(vector<int>{});
		depth1.push_back(-1);
		depth2.push_back(-1);
	}
	for (int i = 1; i <= t; i++) {
		int flag = 1;
		int a;
		cin >> a;
		while (flag) {
			int b;
			cin >> a;
			if (a == -1)flag=0;
			else {
				cin >> b;
				nodes[i].push_back(a);
				nodes[a].push_back(i);
				length[i].push_back(b);
				length[a].push_back(b);
			}
		}
	}
	bfsq.push(pair<int, int>(t / 2, 0));
	while (bfsq.size()) {
		go1(bfsq.front());
		bfsq.pop();
	}
	int maxval = -1, max = -1;
	for (int i = 1; i <= t; i++) {
		if (depth1[i] > maxval) {
			max = i;
			maxval = depth1[i];
		}
	}
	bfsq.push(pair<int,int>(max,0));
	//cout << it;
	while (bfsq.size()) {
		go2(bfsq.front());
		bfsq.pop();
	}
	maxval = -1, max = -1;
	for (int i = 1; i <= t; i++) {
		if (depth2[i] > maxval) {
			max = i;
			maxval = depth2[i];
		}
	}

	cout << maxval;
}