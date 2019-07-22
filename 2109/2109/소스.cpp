#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
priority_queue<int>b;

int main() {
	int x; cin >> x;
	while (x--) {
		int p, d;
		cin >> p >> d;
		pq.push(pair<int, int>(d, p));
	}
/*	while (!pq.empty()) {
		cout << pq.top().first<<" "<<pq.top().second<<endl;
		pq.pop();
	}*/
	int sum = 0;
	while (!pq.empty()) {
		sum += pq.top().second;
		b.push(-pq.top().second);
		if (b.size() > pq.top().first) {
			sum += b.top();
			b.pop();
		}
		pq.pop();
	}
	cout << sum;
}