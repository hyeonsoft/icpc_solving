#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int t,n;
	cin >> n;
	cin >> t;
	int elap = 0;
	while (t--) {
		int time;
		char ans;
		cin >> time >> ans;
		elap += time;
		if (elap >= 210) {
			break;
		}
		if (ans == 'T')n++;
	}
	cout << (n - 1) % 8 + 1;
}