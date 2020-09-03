#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector <string> list;
vector <string> out;
bool checked[1000] = { 0 };
int orgpos[1000];
int getorgpos(string s) {
	for (int i = 0; i < list.size(); i++) {
		if (s == list[i])return i;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		list.push_back(s);
	}
	for (int i = 0; i < list.size(); i++) {
		string s;
		cin >> s;
		out.push_back(s);
		orgpos[i] = getorgpos(s);
	}
	int cnt = 0;
	for (int i = 1; i < list.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (!checked[j] && orgpos[j] > orgpos[i]) {
				checked[j] = true;
				cnt++;
			}
		}
	}
	cout << cnt;
}