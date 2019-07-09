//https://www.acmicpc.net/problem/11652

#include <iostream>
#include <map>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	map<long long int,int> cards;
	int a;
	cin >> a;
	long long int maxcur = 0;
	int max=0;
	while (a--) {
		long long int b;
		cin >> b;
		cards[b]++;
	}
	auto it = cards.begin();
	maxcur = it->first;
	while (it != cards.end()) {
		if (max < it->second) {
			maxcur = it->first;
			max = it->second;
		}
		it++;
	}
	cout << maxcur;
}