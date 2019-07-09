//https://www.acmicpc.net/problem/1302

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map <string, int> list;
	int time;
	cin >> time;
	while (time--) {
		string x;
		cin >> x;
		list[x]++;
	}
	auto it = list.end();
	int max=0;
	string output;
	while (it!=list.begin()) {
		it--;
		if (max <= it->second) {
			output = it->first;
			max = it->second;
		}
	}
	cout << output;
}