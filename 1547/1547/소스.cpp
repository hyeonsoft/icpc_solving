#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int t;
	cin >> t;
	int x[3] = { 1,0,0 };
	while (t--) {
		int a, b;
		cin >> a >> b;
		swap(x[a - 1], x[b - 1]);
	}
	for (int i = 0; i < 3; i++) {
		if (x[i])cout << i + 1;
	}
}