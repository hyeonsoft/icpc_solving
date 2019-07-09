//https://www.acmicpc.net/problem/10825

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class l {
public :
	string name;
	int k;
	int y;
	int s;
	l(string a, int b, int c, int d) {
		name = a;
		k = b;
		y = c;
		s = d;
	}
};

bool cmp(l a, l b) {
	if (a.k > b.k) {
		return 1;
	}
	else if (a.k < b.k) {
		return 0;
	}
	else {
		if (a.y < b.y) {
			return 1;
		}
		else if (b.y < a.y) {
			return 0;
		}
		else {
			if (a.s > b.s) {
				return 1;
			}
			else if (a.s < b.s) {
				return 0;
			}
			else {
				if (a.name < b.name) {
					return 1;
				}
				else{
					return 0;
				}
			}
		}
	}
}

int main() {
	int time;
	cin >> time;
	vector<l> list;
	while (time--) {
		string u;
		int k, y, s;
		cin >> u >> k >> y >> s;
		list.push_back(l{ u,k,y,s });
	}
	sort(list.begin(), list.end(), cmp);
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].name << "\n";
	}
}