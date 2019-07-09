//https://www.acmicpc.net/problem/3047

#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	for (int i = 0; i < 3; i++) {
		int u;
		cin >> u;
		pq.push(u);
	}
	int arr[3];
	char input[4];
	cin >> input;
	for (int i = 0; i < 3; i++) {
		arr[2-i] = pq.top();
		pq.pop();
	}
	for (int i = 0; i < 3; i++) {
		cout << arr[input[i] - 'A']<<" ";
	}
}