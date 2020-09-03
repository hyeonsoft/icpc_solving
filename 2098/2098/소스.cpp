#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimum = 2147483647;
int nodes[17][17];
int t=0;
int allvisit;

void dp(int visit, int cost, int visited, int start) {
	if (visit == start && visited==allvisit) {
		//�ٽ� �ǵ��ƿ��� ��� ��� �湮���� ������ ��
		minimum = min(minimum, cost);
		return;
	}
	//�̹� ���� ��Ҹ� �ٽ� ���� ���
	if ((1 << visit) & visited)return;
	//�̹� ��ҿ� �湮���� ����
	visited |= (1 << visit);
	//���� �湮��
	for (int i = 1; i <= t; i++) {
		if (i != visit && nodes[visit][i] != 0) {
			dp(i, cost + nodes[visit][i], visited, start);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		allvisit |= (1 << i);
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= t; j++) {
			cin >> nodes[i][j];
		}
	}
	dp(1, 0, 0, 1);
	cout << minimum;
}