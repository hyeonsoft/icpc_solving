#include <iostream>
#include <algorithm>
using namespace std;

int h[1000][3];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h[i][0] >> h[i][1] >> h[i][2];
		if (i) {
			h[i][0] += min(h[i - 1][2], h[i - 1][1]);
			h[i][1] += min(h[i - 1][2], h[i - 1][0]);
			h[i][2] += min(h[i - 1][0], h[i - 1][1]);
		}
	}
	cout << min(min(h[t - 1][0],h[t-1][1]), h[t - 1][2]);
}