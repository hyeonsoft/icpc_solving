#include <iostream>
#include <algorithm>
int numbers[5000];

using namespace std;

int main() {
	int n;
	
	cin >> n;
	int minimum = 5000;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers, numbers + n);
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (numbers[i + 1] % numbers[i])cnt++;
	}
	cout << cnt;
}