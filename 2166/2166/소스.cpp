#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
typedef pair<long long int, long long int> P;
typedef pair<long long int, long long int> V;
P point[10001];
int ccw(V v1, V v2) {
	long long int x = v1.first*v2.second - v2.first*v1.second;
	if (x > 0)return 1;
	else if (x == 0)return 0;
	else return -1;
}
double samgak(P v1, P v2, P v3) {
	V n1{ v2.first - v1.first, v2.second-v1.second };
	V n2{ v3.first - v1.first, v3.second - v1.second };
	return (n1.first*n2.second - n2.first*n1.second)/2.0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> point[i].first>>point[i].second;
	}
	double ans{ 0 };
	for (int i = 1; i < n - 1; i++) {
		ans += samgak(point[0], point[i], point[i + 1]);
	}
	printf("%.1f", fabs(ans));
}