#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, w;
int room[20000];

int dp(int idx, int count, int bp, int zeropos) {
	bp >>= 1;
	int maxi = count;
	if (idx == n - 1) {
		if(bp&1)return dp(2 * n - 1, count, bp, zeropos);
		//아래
		if (room[idx] + room[idx + n] <= w && (bp & 1) == 0) {
			maxi = max(dp(2 * n - 1, count + 1, bp | 1, 3), maxi);
		}
		//오른쪽
		if ((zeropos & 1)==0) {
			if (room[idx] + room[0] <= w ) {
				maxi = max(dp(2 * n - 1, count + 1, bp | 2, 3), maxi);
			}
		}
		return max(dp(2*n-1, count, bp, zeropos), maxi);
	}
	if (idx == 2 * n - 1) {
		if (bp & 1)return count;
		//오른쪽
		if ((zeropos & 2) == 0) {
			if (room[idx] + room[n] <= w) {
				return count + 1;
			}
		}

		return count;
	}
	int nextIdx = ((idx + n >= 2 * n) ? idx + 1 - n : idx + n);
	if (bp & 1) {
		return dp(nextIdx, count, bp, zeropos);
	}
	else {
		//오른쪽 결합
		if (room[idx] + room[idx + 1] <= w) {
			maxi = max(dp(nextIdx, count + 1, bp | 1 << 2, idx ==0||idx==n ? (idx==0?1:zeropos+2) : zeropos), maxi);
		}
		//아랫쪽 결합
		if (idx < n) {
			if (room[idx] + room[idx + n] <= w && (bp&1)==0) {
				maxi = max(dp(nextIdx, count + 1, bp | 1 << 1, idx==0 ? 3 : zeropos), maxi);
			}
		}
		maxi = max(dp(nextIdx, count, bp, zeropos), maxi);
	}
	return maxi;
}

void test() {
	cin >> n >> w;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < n; x++) {
			cin >> room[y*n+x];
		}
	}
	cout<<2*n-dp(0, 0, 0, 0);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int caseOfTests;
	cin >> caseOfTests;
	while (caseOfTests--) {
		test();
	}
}