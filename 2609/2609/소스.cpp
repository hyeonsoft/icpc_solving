#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int n = a, m = b;
	while (b!=0) {
		if (a > b)swap(a, b);
		int r = b - (b / a)*a;
		b = r;
	}
	cout << a<<endl;
	if (n > m)swap(n, m);
	a = 0;
	while (1) {
		a++;
		if ((a*m) % n == 0)break;
	}
	cout << a * m;
}