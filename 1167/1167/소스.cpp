#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>>nodes;
bool dp1toggle[100001]{ 0 };
bool dp2toggle[100001]{ 0 };

pair<int, long long int>deepest = pair<int, long long int>{ 0, 0 };
pair<int, long long int>deepest2 = pair<int, long long int>{ 0, 0 };

void dp1(int idx, long long int depth) {
	if (dp1toggle[idx])return;
	dp1toggle[idx] = 1;
	for (auto x : nodes[idx]) {
		dp1(x.first, depth+x.second);
	}
	if (depth > deepest.second)deepest = pair<int, long long int>{ idx, depth };
}

void dp2(int idx, long long int depth) {
	if (dp2toggle[idx])return;
	dp2toggle[idx] = 1;
	for (auto x : nodes[idx]) {
		dp2(x.first, depth + x.second);
	}
	if (depth > deepest2.second)deepest2 = pair<int, long long int>{ idx, depth };
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i <= t; i++) {
		nodes.push_back(vector<pair<int,int>>{});
	}
	for (int i = 1; i <= t; i++) {
		int x, y;
		int s;
		cin >> s;
		while (true) {
			cin >> x;
			if (x == -1)break;
			cin >> y;
			nodes[s].push_back(pair<int, int>{x, y});
		}
	}
	//1ȸ�� dp�� ���� �� ������ ã�Ƴ���.
	dp1(1, 0);
	//2ȸ�� dp�� 1ȸ�� dp���� ���� �������� ���� �� ������� �Ÿ��� ���Ѵ�.
	dp2(deepest.first, 0);
	cout << deepest2.second;
}