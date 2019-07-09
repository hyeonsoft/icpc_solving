#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	//cin.tie(0);
	//cout.tie(0);
	stack <char> left;
	stack <char> right;
	//ios_base::sync_with_stdio(false);
	string a;
	char b;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		left.push(a[i]);
	}
	int time;
	scanf("%d", &time);
	while (time--) {
		scanf(" %c", &b);
		switch (b) {
		case 'L':
			if (left.size()) {
				right.push(left.top());
				left.pop();
				
			}
			break;
		case 'D':
			if (right.size()) {
				left.push(right.top());
				right.pop();
				
			}
			break;
		case 'P':
			scanf(" %c", &b);
			left.push(b);
			break;
		case 'B':
			if (left.size()) {
				left.pop();
				
			}
			break;
		}
	}
	while (left.size()) {
		right.push(left.top());
		left.pop();
	}
	while (right.size()) {
		cout << right.top();
		right.pop();
	}
}