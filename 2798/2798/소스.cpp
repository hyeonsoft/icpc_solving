#include <iostream>
#include <vector>
using namespace std;


int main() {;
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> card;
	while (n--) {
		int u;
		cin >> u;
		card.push_back(u);
	}
	int max = 0;
	for (int a = 0; a < card.size()-2; a++) {
		for (int b = a+1; b < card.size()-1; b++) {
			for (int c = b+1; c < card.size(); c++) {
				if (card[a] + card[b] + card[c] > max&&card[a]+card[b]+card[c]<=k)max = card[a] + card[b] + card[c];
			}
		}
	}
	cout << max;
}