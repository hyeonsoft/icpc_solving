#include <iostream>
#include <vector>
using namespace std;

int board[100][100]{ 0 };
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n ;
	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int p = x; p < x + 10; p++) {
			for (int o = y; o < y + 10; o++) {
				board[p][o] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int o = 0; o < 100; o++) {
			sum += board[i][o];
		}
	}
	cout << sum;
}