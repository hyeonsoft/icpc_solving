#include <iostream>
#include <cmath>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int time;
	cin >> time;
	while (time--) {
		int x1, x2, r1, y1, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int a = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		int b = (r1 + r2)*(r1+r2);
		
//		cout << a << " " << b << " " << pow((double)a, 0.5) << endl;

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)cout << -1;
			else cout << 0; //0;
		}
		else if (pow((double)a, 0.5) + r1 == (double)r2 || pow((double)a, 0.5) + r2 == (double)r1) {
			cout << 1;
		}
		else if (pow((double)a, 0.5) + r1 < (double)r2 || pow((double)a, 0.5) + r2 < (double)r1) {
			cout << 0; // 0;
		}
		else if (a ==b) {
			cout << 1;
		}
		else if (a > b) {
			cout << 0;
		}

		else {
			cout << 2;
		}
		cout << "\n";
	}
}