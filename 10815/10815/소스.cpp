#include <iostream>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	map<int, int> a;
	int t;
	cin >> t;
	while (t--) {
		int b;
		cin >> b;
		a[b] = 1;
	}
	cin >> t;
	while (t--) {
		int b;
		cin >> b;
		if (a[b] == 1)cout << "1 ";
		else cout << "0 ";
	}
}