#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int startpos = -2e9;
	int endpos=-2e9;
	vector<pair<int, int>>n;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		n.push_back(pair<int, int>(s, e));
	}
	sort(n.begin(), n.end());
	for (int i = 0; i < N; i++) {
		if (startpos == -2e9) {
			startpos = n[i].first;
			endpos = n[i].second;
		}
		else if (n[i].first < endpos)endpos = max(endpos, n[i].second);
		else {
			sum += endpos - startpos;
			startpos = n[i].first;
			endpos = n[i].second;
		}
	}
	if (startpos != -2e9)sum += endpos - startpos;
	cout << sum;
}