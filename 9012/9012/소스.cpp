#include <iostream>
#include <string>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int x;
	cin >> x;
	while (x--) {
		string a;
		cin >> a;
		int u = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '(') {
				u++;
			}
			else if (a[i] == ')') {
				u--;
			}
			if (u == -1) {
				break;
			}
		}
		if (u == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}