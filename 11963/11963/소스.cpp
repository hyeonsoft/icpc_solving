#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int pay[50001];
bool occy[100001];
vector<int>bessie;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pay[i];
		occy[pay[i]] = 1;
	}
	for (int i = 1; i <= 2 * N; i++) {
		if (!occy[i])bessie.push_back(i);
	}
	sort(pay, pay + N/2);
	sort(pay + N / 2, pay + N);
	int score = 0;
	int u = 0;
	for (int i = 0; i < N / 2; i++) {
		if (pay[u] < bessie[N/2+i]) {
			score++;
			u++;
		}
	}
	u = 0;
	for (int i = 0; i < N/2; i++) {
		if (pay[i+N/2] > bessie[u]) {score++;
			u++;
		}
	}
	cout << score;
}