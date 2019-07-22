//잘못만들음

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int s[100000]{ 0 };
	int e[100000]{ 0 };
	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		if (a == b)b++;
		s[i] = a;
		e[i] = b;
	}
	sort(&s[0], &s[n]);
	sort(&e[0], &e[n]);
	int ma = 0;
	int t=0;
	int cnt = 0;
	int i = 0, j = 0;
	for (;j<n&&i<n;) {

		t = min(s[i], e[j]);

		while (t == s[i]) {
			cnt++;
			i++;
		}

		while (t == e[j]) {
			cnt--;
			j++;
		}

		ma = max(ma, cnt);

	}
	cout << ma;
}