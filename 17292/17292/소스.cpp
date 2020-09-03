#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;


int main() {
	string cards;
	cin >> cards;
	vector<pair<char, bool>>a; //number, isblack
	for (int i = 0; i < cards.size(); i++) {
		char num = cards[i] - '0';
		if (num > 10)num = num + '0' - 'a' + 10;
		i++;
		bool isblack = (cards[i] == 'b' ? 1 : 0);
		i++;
		a.push_back(pair<char, bool>{num, isblack});
	}
	vector<pair<int,pair<char, char>>>pairs;
	for (int i = 0; i < 5; i++) {
		for (int p = i + 1; p < 6; p++) {
			int val{ 0 };  // bit : 0 1 1 1 / 1234 / 1234 / 000 1
			if (abs(a[i].first - a[p].first) == 1 || abs(a[i].first - a[p].first) == 14 )val += 1 << 14;
			if (a[i].first == a[p].first)val += 1 << 13;
			if (a[i].second == a[p].second)val += 1 << 12;
			val += max(a[i].first, a[p].first) << 8;
			val += min(a[i].first, a[p].first) << 4;
			val += (a[i].first > a[p].first ? a[i].second : a[p].second);
			pairs.push_back(pair<int, pair<char, char>>{-val, pair<char, char>{i, p}});
		}
	}
	sort(pairs.begin(), pairs.end());
	for (auto x : pairs) {
		int firstnum = a[x.second.first].first;
		char firstchar = a[x.second.first].second?'b':'w';
		int secondnum = a[x.second.second].first;
		char secondchar = a[x.second.second].second?'b':'w';
		cout << (char)(firstnum > 9 ? firstnum - 10 + 'a' : firstnum + '0') << firstchar;
		cout << (char)(secondnum > 9 ? secondnum - 10 + 'a' : secondnum + '0') << secondchar;
//		cout << " " << hex << x.first; //debug
		cout << '\n';
	}
}