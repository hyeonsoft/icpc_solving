#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, s;
	vector<int>vt1, vt2;
	cin >> n >> s;
	int arr[41];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (long long int i=0; i < (1 << n/2); i++) {
		int sum = 0;
		for (long long int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				sum += arr[j];
			}
		}
		vt1.push_back(sum);
	}
	for (long long int i=0; i < (1 << (n -n/2)); i++) {
		int sum = 0;
		for (long long int j = 0; j < (n-n/2); j++) {
			if (i&(1 << j)) {
				sum += arr[j+n/2];
			}
		}
		vt2.push_back(sum);
	}
	long long int cnt{ 0 };
	sort(vt1.begin(), vt1.end());
	sort(vt2.begin(), vt2.end());
	for (int x : vt1) {
		cnt += upper_bound(vt2.begin(), vt2.end(), s - x) - lower_bound(vt2.begin(), vt2.end(), s - x);
	}
	if (s == 0)cnt--;
	cout << cnt;
}