#include <iostream>
#include <vector>
using namespace std;
int honeycomb[15][40];
bool isgroup[15][40]{ 0 };

int t, f;
pair<int, int> go1(int i, int j) {
	return pair<int, int>{i, j - 2};
}
pair<int, int> go2(int i, int j) {
	return pair<int, int>{i, j + 2};
}
pair<int, int> go3(int i, int j) {
	return pair<int, int>{i+1, j - 1};
}
pair<int, int> go4(int i, int j) {
	return pair<int, int>{i-1, j - 1};
}
pair<int, int> go5(int i, int j) {
	return pair<int, int>{i+1, j + 1};
}
pair<int, int> go6(int i, int j) {
	return pair<int, int>{i-1, j + 1};
}

int main() {
	cin >> t >> f;
	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j <= 40; j++) {
			honeycomb[i][j] = -2147483648;
		}
	}
	for (int i = 1; i <= 2 * t - 1; i++) {
		int blank = t - i; blank = abs(blank);
		for (int j = 1 + blank; j <= 4*t-3-blank; j += 2) {
			cin >> honeycomb[i][j];
		}
	}
	//������ + ����������, -���������� �׷��� ���´�.
	for (int i = 1; i <= 2 * t - 1; i++) {
		int blank = t - i; blank = abs(blank);
		for (int j = 1 + blank; j <= 4 * t - 3 - blank; j += 2) {
			cin >> honeycomb[i][j];
		}
	}
	//�� + �׷츶�� ����Ž���� ���ؼ� �ִ� ���� �� �ִ� ���������� ���Ѵ�.
	//�������� ���� �� �ʿ��� �˻����� ���̱� ���ؼ� ����� �ش� ���� ���� �� ��� �̵溸�� ������ ������.
}