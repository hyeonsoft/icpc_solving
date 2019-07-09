#include <iostream>
#include <queue>


using namespace std;

int main() {
	queue <int> card;
	int a;
	cin >> a;
	for (int i = 0; i < a;) {
		card.push(++i);
	}
	while (card.size() > 1) {
		card.pop();
		card.push(card.front());
		card.pop();
	}
	cout << card.front();
}