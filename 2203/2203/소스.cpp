#include <iostream>
#include <vector>


using namespace std;

vector <int> given;

int n, m;
int cnt{ 0 };



int main() {
	cin >> n >> m;
	while (n--) {
		int t;
		cin >> t;
		given.push_back(t);
	}
	vector <int> a;
	for (int x = 0; x < given.size(); x++) {
		a.push_back(0);
		for (int i = 0; i < a.size(); i++) {
			a[i] += given[x];
			if (a[i] > m) {
				auto it = a.begin() + i;
				a.erase(it);
				i--;
			}
			else if (a[i] == m) {
				cnt++;
				auto it = a.begin() + i;
				a.erase(it);
				i--;
			}
		}
	}
	cout << cnt;
}