#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k, startidx;
long long int tree[4000000];
void construct() {
	for (int i = startidx - 1; i > 0; i--) {
		tree[i] =( tree[i * 2] * tree[i * 2 + 1])%1000000007;
	}
}
void update(int idx, int val) {
	idx = idx + startidx;
	tree[idx] = val;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = (tree[idx] = tree[idx * 2] * tree[idx * 2 + 1])% 1000000007;
		idx /= 2;
	}
}
long long int search(int left, int right, int leftBound, int rightBound, int pos) {
	if (leftBound > right || rightBound < left)return 1;
	if (leftBound <= left && right <= rightBound)return tree[pos];
	int mid = (left + right) / 2;
	return ((search(left, mid, leftBound, rightBound, pos * 2) % 1000000007)
		*(search(mid + 1, right, leftBound, rightBound, pos * 2 + 1) % 1000000007))%1000000007;
}
int main() {
	cin >> n >> m >> k;
	startidx = 1;
	while (startidx < n)startidx *= 2;
	for (int i = startidx; i <= startidx * 2; i++)tree[i] = 1;
	for (int i = 0; i < n; i++) {
		cin >> tree[i + startidx];
	}
	construct();
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout << search(0, startidx - 1, b - 1, c - 1, 1) % 1000000007 << "\n";
		}
	}
}