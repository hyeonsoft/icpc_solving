#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a[6];
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	int sum = 0;
	sum += a[5];
	sum += a[4];
	if (a[4] * 11 > a[0])a[0] = 0;
	else a[0] -= a[4] * 11;
	sum += a[3];
	if (a[3] * 5 > a[1]) {
		a[1] = 0;
		a[0] -= (a[3] * 5 - a[1]) * 4;
		if (a[0] < 0)a[0] = 0;
	}
	else {
		a[1] -= a[3] * 5;
	}
	sum += a[2] / 4;
	if (a[2] % 4) {
		sum++;
		int u = 7 - (a[2]%4) * 2; //여기까지 체크완료
		if (u >= a[1]) {
			int left = (4 - (a[2] % 4)) * 9 - 4 * a[1];
			a[0] -= left;
			if (a[0] < 0)a[0] = 0;
			a[1] = 0;
		}
		else {
			a[1] -= u;
			int left = (4 - (a[2] % 4)) * 9 - 4 * u;
			a[0] -= left;
			if (a[0] < 0)a[0] = 0;
		}
	}
	sum += a[1] / 9;
	if (a[1] %= 9) {
		sum++;
		int left = 36 - a[1] * 4;
		a[0] -= left;
		if (a[0] < 0)a[0] = 0;
	}
	sum += a[0] / 36;
	if (a[0] % 36) {
		sum++;
	}
	cout << sum;
}

/*
int main() {
	int a[6];
	int all=0;
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
		all += a[i];
	}
	int sum = 0;
	
	while(all>0){
		int square[6][6]{ 0 };
		for (int i = 5; i >= 0; i--) {
			if (a[i]>0) {
				START:
				for (int x = 0; x < 6; x++) {
					for (int y = 0; y < 6; y++) {
						if (square[x][y]==0&&x + i < 6 && y + i < 6&&a[i]>0) {
							cout << x <<" "<< y << " "<< i<<" "<<sum<<" " <<a[i]<<" "<<all<<endl; //디버그
							int flag = 0;
							for (int q = 0; q <= i+x; q++) {
								for (int w = 0; w <= y+i; w++) {
									if (square[q][w]) {
										flag = 1;
										break;
									}
								}
								if (flag)break;
							}
							if(!flag){
								for (int q = 0; q <= x+i; q++) {
									for (int w = 0; w <= y+i; w++) {
										square[q][w] = i+1;
									}
								}
								a[i]--;
								all--;
								goto START;
							}
						}
					}
				}
			}
		}
		cout << endl;
		for (int x = 0; x < 6; x++) {
			for (int y = 0; y < 6; y++) {
				cout << square[x][y];
			}
			cout << endl;
		}
		cout << endl;
		sum++;
	}
	cout << sum;
}
*/