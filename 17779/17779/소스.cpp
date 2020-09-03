#include <iostream>
#include <vector>
#include <algorithm>

int td[21][21]{ 0 }, lr[21][21]{ 0 };
int p[21][21];
int n, all{ 0 };
using namespace std;



int s(int x,int y,int  d1,int d2) {
	int area1{ 0 };
	for (int a = 1; a < x + d1; a++) {
		if (a < x) {
			
		}
		else {
			area1 += td[a][y-a-1+x];
		}
	}
	int area2{ 0 };
	for (int a = y + 1; a <= n; a++) {
		if (y <= x + d2) {
			area2 += lr[a - y + x][a];
		}
		else {
			area2 += lr[x + d2][a];
		}
	}
	int area3{ 0 };
	for (int a=1;a<y-d1+d2;a++){
		if (a < y - d2) {
			area3 += lr[n][a] - lr[x + d1-1][a];
		}
		else {
			area3 += lr[n][a] - lr[x+d1+a-(y-d2-1)][a];
		}
	}
	int area4{ 0 };
	for (int a = y - d1 - d2; a <= n; a++) {
		if (a > y + d2) {
			area4 += lr[n][a] - lr[x+d2][a];
		}
		else {
			area4 += lr[n][a] - lr[x + d1 + d2 + 1 - (a - x - d1 - d2)][a];
		}
	}
	int area5{ all - area1 - area2 - area3 - area4 };
	int m = min(area1, min(area2, min(area3, min(area4, area5))));
	int M = max(area1, max(area2, max(area3, max(area4, area5))));
	cout << area1 << " " << area2 << " " << area3 << " " << area4 << " " << area5 << endl;
	return M - m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> p[x][y];
			all += p[x][y];
		}
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			lr[x][y] = lr[x - 1][y] + p[x][y];
		}
	}
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			td[x][y] = lr[x][y-1] + p[x][y];
		}
	}
	cout << s(2, 4, 2, 2);
}