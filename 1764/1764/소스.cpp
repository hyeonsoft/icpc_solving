//https://www.acmicpc.net/problem/1764

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, int> lists;
	int a, b;
	cin >> a>>b;
	while (a--) {
		string x;
		cin >> x;
		lists.insert({ x,1 });
	}
	int sum=0;
	while (b--) {
		string x;
		cin >> x;
		auto it =lists.find(x);
		if (it != lists.end()) {
			it->second++;
			sum++;
		}
	}
	cout << sum << "\n";
	auto it = lists.begin();
	while (it != lists.end()) {
		if (it->second == 2) {
			cout << it->first << "\n";
		}
		it++;
	}
}