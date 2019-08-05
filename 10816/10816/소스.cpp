#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int a[500000];
	int t;
	cin >> t;
	for(int i=0;i<t;i++) {
		int b;
		cin >> b;
		a[i] = b;
	}
	sort(a, a+t);
	int x;
	cin >> x;
	while (x--) {
		int b;
		cin >> b;
		cout << upper_bound(a, a+t, b)-lower_bound(a, a+t, b) << " ";
	}
}