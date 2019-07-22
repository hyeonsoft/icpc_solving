#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool com(int a, int b) { return a > b; }

int main() {
	int N;
	vector<int>minutes;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		minutes.push_back(a);
	}
	sort(minutes.begin(), minutes.end(), com);
	int sum = 0;
	for (int i = 0; i < minutes.size(); i++)sum += (i + 1)*minutes[i];
	cout << sum;
}