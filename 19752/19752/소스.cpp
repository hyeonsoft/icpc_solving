#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int d1, d2, d3;
	cin >> d1>> d2>> d3;
	float A = d1 + d2 + d3;
	float a = (A - 2 * d3) / 2;
	float b = (A - 2 * d2) / 2;
	float c = (A - 2 * d1) / 2;
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << -1;
	}
	else {
		cout << 1 << endl;
		cout << fixed;
		cout <<setprecision(1)<< a << " " << b << " " << c;
	}
}