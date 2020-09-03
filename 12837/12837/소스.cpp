#include <iostream>
#include <algorithm>
#include <vector>

int n, q, idxstart{ 1 };
long long int tree[4000000]{ 0 };

void construct() {
	//not used
}
void update(int idx, int val) {

}

int main() {
	using namespace std;
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	while (n > idxstart) {
		idxstart *= 2;
	}
	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(idxstart + b, c);
		}
	}
}