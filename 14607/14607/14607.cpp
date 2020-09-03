#include <iostream>
#include <map>

using namespace std;
map<int, long long int> box{};

long long int getm(long long int x) {
	if (x == 0) return 0;
	if (x == 1)return 0;
	long long int t;
	if (box[x] == 0) {
		t = (x / 2) * (x - x / 2) + getm(x / 2) + getm(x - x / 2);
		box[x] = t;
		return t;
	}
	else {
		return box[x];
	}
}

int main() {
	int n;
	cin >> n;
	cout << getm(n);
}