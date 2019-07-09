#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int min = -1;
	int x, y;
	cin >> x >> y;
	vector<string> a;
	int u = x;
	while (u--) {
		string i;
		cin >> i;
		a.push_back(i);
	}
	string W[]{ "WB","BW" };
	for (int i = 0; i <= x - 8; i++) {
		for (int p = 0; p <= y - 8; p++) {
			int l = 0;
			//W
			for (int d = i; d < i + 8; d++) {
				for (int f = p; f < p + 8; f++) {
					if (W[d % 2][f % 2] == a[d][f])l++;
				}
			}
			if (min == -1 || min > l)min = l;
			//B
			l = 64 - l;
			if (min > l)min = l;
		}
	}
	cout << min;
}