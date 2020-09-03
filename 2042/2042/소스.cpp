#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, k;
int startIDX=1;
long long int tree[4000000];

void constructTree() {
	for (int i = startIDX - 1; i > 0; i--) {
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

void updateTree(int index, int val) {
	index += startIDX;
	tree[index] = val;
	for (int i = index/2; i > 0; i /= 2) {
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

long long int searchTree(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound) {
		return tree[pos];
	}
	int mid = (left + right) / 2;
	return searchTree(leftBound, rightBound, left, mid, pos*2) +
		searchTree(leftBound, rightBound, mid+1, right, pos*2+1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	while (startIDX < n) {
		startIDX *= 2;
	}
	for (int i = 0; i < n; i++) {
		cin >> tree[startIDX + i];
	}
	constructTree();
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			updateTree(b-1, c);
		}
		else {
			cout << searchTree(b - 1, c - 1, 0, startIDX - 1, 1) << "\n";
		}
	}
}