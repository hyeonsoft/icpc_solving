#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class words {
public:
	string word;
};

int comp(words& a, words& b) {
	if (a.word.length() != b.word.length())return a.word.length() < b.word.length();
	return a.word < b.word;
}

words x[20000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i].word;
	}
	sort(x, x + n, comp);
	string prev = "";
	for (int i = 0; i < n; i++) {
		if (x[i].word == prev)continue;
		cout << x[i].word << '\n';
		prev = x[i].word;
	}
}