#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
typedef __int64 ll;
using namespace std;
long long int n, lx, ly, bx, by;
vector<pair<long long int, long long int>>mi;
vector<pair<long long int, long long int>>miy;
set<pair<ll, ll>>visited;
queue<pair<pair<ll, ll>,int>>bfsq;//x,y,depth

int depth = 1;
int flag=0; int visited[100001]{ 0 };
void bfs() {
	
}
int main() {
	cin >> n >> lx >> ly >> bx >> by;
	for (int i = 0; i < n; i++) {
		long long int x, y;
		cin >> x >> y;
		mi.push_back(pair<long long int, long long int>(x, y));
		miy.push_back(pair<long long int, long long int>(y, x));
	}
	sort(mi.begin(), mi.end());
	sort(miy.begin(), miy.end());
	bfsq.push(pair<pair<ll,ll>,int>(pair<ll,ll>(lx, ly),0));
	if (bfsq.size() && flag == 0) {
		bfs();
	}
}