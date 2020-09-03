#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, m, startidx=1;

int treemax[4000000]{ 0 };
int treemin[4000000];
void editone(int idx) {
	treemax[idx] = max(treemax[2 * idx], treemax[2 * idx + 1]);
	treemin[idx] = min(treemin[2 * idx], treemin[2*idx + 1]);
}
void maketree() {
	for (int i = startidx - 1; i > 0; i--) {
		editone(i);
	}
}
int searchmax(int left, int right, int leftBound, int rightBound, int pos) {
	if (leftBound > right || rightBound < left)return 0;
	if (leftBound <= left && right <= rightBound)return treemax[pos];
	int mid{ (left + right) / 2 };
	return max(searchmax(left, mid, leftBound, rightBound, pos * 2),
		searchmax(mid + 1, right, leftBound, rightBound, pos * 2 + 1));
}
int searchmin(int left, int right, int leftBound, int rightBound, int pos) {
	if (leftBound > right || rightBound < left)return 2147483647;
	if (leftBound <= left && right <= rightBound)return treemin[pos];
	int mid{ (left + right) / 2 };
	return min(searchmin(left, mid, leftBound, rightBound, pos * 2),
		searchmin(mid + 1, right, leftBound, rightBound, pos * 2 + 1));
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	while (startidx < n)startidx *= 2;
	for (int i = startidx; i <= 2 * startidx; i++)treemin[i] = 2147483647;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		treemax[i + startidx] = t;
		treemin[i + startidx] = t;
	}
	maketree();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << searchmin(0, startidx - 1, a - 1, b - 1, 1) << " " << searchmax(0, startidx - 1, a - 1, b - 1, 1) << "\n";
	}
}