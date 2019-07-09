//https://www.acmicpc.net/problem/2455

#include <iostream>

using namespace std;

int main() {
	int max = 0;
	int t = 0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		t += b;
		t -= a;
		if (t > max)max = t;
	}
	cout << max;
}