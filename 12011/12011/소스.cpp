#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>>cows;
vector<pair<int, int>>cows2;
int x1, y1;
int x0=2147483647, y0=2147483647;
long long int square(int i) {
	return (long long int)i*(long long int)i;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x1 = max(x, x1);
		y1 = max(y, y1);
		x0 = min(x, x0);
		y0 = min(y, y0);
		cows.push_back(pair<int, int>(x, y));
		cows2.push_back(pair<int, int>(y, x));
	}
	sort(cows.begin(), cows.end());
	sort(cows2.begin(), cows2.end());
	int mind[50001], maxd[50001], mind2[50001], maxd[50001];
	//���ʿ��� ���������� ���鼭 �߶����, ������ �Ʒ������� ���鼭 �߶���� �� ���������� �ִ� �ּҸ� ã�Ƽ� ���̸� ���Ѱ� ���ϸ� �ȴ�


}