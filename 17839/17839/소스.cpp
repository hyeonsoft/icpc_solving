#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string>list;
map<string, set<string>> a;
void df(string now) {
	if (list.find(now)!=list.end())return;
	list.insert(now);
	for (auto x : a[now]) {
		df(x);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string b, c, d;
		cin >> b >> c >> d;
		a[b].insert(d);
	}
	df("Baba");
	//sort(list.begin(), list.end());
	for (auto x : list) {
		if (x == "Baba")continue;
		cout << x << "\n";
	}
}