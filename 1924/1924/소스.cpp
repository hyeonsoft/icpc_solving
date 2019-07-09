#include <iostream>
#include <string>
using namespace std;

int main() {
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int m, d;
	cin >> m >> d;
	int w = 0;
	string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	for (int t = 1; t < m; t++) {
		w += month[t - 1];
	}
	w += d-1;
	cout << week[w % 7];
}