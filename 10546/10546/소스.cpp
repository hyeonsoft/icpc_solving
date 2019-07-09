//https://www.acmicpc.net/problem/10546

#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {
	map<string, int> list;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		string x;
		cin >> x;
		list[x]++;
	}
	for (int i = 0; i < a-1; i++) {
		string x;
		cin >> x;
		list[x]--;
	}
	auto it = list.begin();
	while (it != list.end()) {
		if (it->second)cout << it->first;
		it++;
	}
}