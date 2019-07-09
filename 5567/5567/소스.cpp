#include <iostream>
#include <cstring>
using namespace std;

char ren[501][501]{ 0 };
char check[501]{ 0 };
int s{ 0 };

void find(int n, int d) {
	if (d < 2) {
		for (int i = 1; i <= s; i++) {
			if (ren[n][i]) {
				if (check[i] > d + 1 || check[i] == -1) {
					check[i] = d + 1;
					find(i, d + 1);
				}
			}
		}
	}
}

int main() {
	memset(check, -1, sizeof(check));
	cin >> s;
	int n;
	cin >> n;
	while (n--) {
		int t, v;
		cin >> t >> v;
		ren[t][v] = 1;
		ren[v][t] = 1;
	}
	check[1] = 0;
	find(1,0);
	int cnt = 0;
	for (int i = 1; i <= s; i++) {
		if (check[i] > 0 && check[i] <= 2)cnt++;
	}
	cout << cnt;
}