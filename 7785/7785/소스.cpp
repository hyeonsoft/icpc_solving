//https://www.acmicpc.net/problem/7785

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	set<string> lis;
	int time;
	cin >> time;
	while (time--) {
		string input;
		string cmd;
		cin >> input >> cmd;
		if (cmd[0] == 'e') {
			lis.insert(input);
		}
		else {
			auto it = lis.find(input);
			lis.erase(it);
		}
	}
	auto it = lis.end();
	while (it != lis.begin()) {
		it--;
		cout << *it << "\n";
	}
}