//http://icpc.me/2503

#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	vector <int> lists;

	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			for (int c = 1; c <= 9; c++) {
				if (a != b && b != c && c != a) {
					lists.push_back(a * 100 + b * 10 + c);
				}
			}
		}
	}

	int time;
	cin >> time;
	while (time--) {
		vector <int>eraselist;
		int strike;
		int ball;
		int input;
		cin >> input >> strike >> ball;
		int in[3];
		in[0] = input / 100;
		in[1] = (input % 100) / 10;
		in[2] = input % 10;
		for (int i = 0; i < lists.size(); i++) {
			int l[3];
			l[0] = lists[i] / 100;
			l[1] = (lists[i] % 100) / 10;
			l[2] = lists[i] % 10;
			int s=0, b=0;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if (in[x] == l[y]) {
						if (x == y) {
							s++;
						}
						else {
							b++;
						}
					}
				}
			}
			if (b != ball || s != strike) {
				lists[i] = 0;
			}
		}
	}
	int sum = 0;
	for (int x = 0; x < lists.size(); x++) {
		if (lists[x])sum++;
	}
	cout << sum;
}