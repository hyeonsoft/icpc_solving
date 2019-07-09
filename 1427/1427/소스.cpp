//https://www.acmicpc.net/problem/1427

#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	string a;
	cin >> a;
	priority_queue<int> u;
	for (int i = 0; i < a.size(); i++) {
		u.push((a[i] - '0'));
	}
	while (u.size()) {
		cout << u.top();
		u.pop();
	}
}