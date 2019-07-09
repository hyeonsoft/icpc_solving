#include <iostream>
#include <string>

using namespace std;

void move(int &x1,int &y1,string i) {
	if (i == "L") {
		x1--;
	}
	if (i == "R") {
		x1++;
	}
	if (i == "T") {
		y1++;
	}
	if (i == "B") {
		y1--;
	}
	if (i == "LT") {
		x1--;
		y1++;
	}
	if (i == "RT") {
		x1++;
		y1++;
	}
	if (i == "LB") {
		x1--;
		y1--;
	}
	if (i == "RB") {
		x1++;
		y1--;
	}
}

int main() {
	int x1, x2, y1, y2;
	string i;
	cin >> i;
	x1 = i[0] - 'A';
	y1 = i[1] - '1';
	cin >> i;
	x2 = i[0] - 'A';
	y2 = i[1] - '1';
	int t;
	cin >> t;
	while (t--) {
		cin >> i;
		int ox = x1;
		int oy = y1;
		move(x1, y1, i);
		if (x1 < 0 || x1>7 || y1 < 0 || y1>7) {
			x1 = ox;
			y1 = oy;
		}
		else if(x1==x2&&y1==y2){
			int tx = x2;
			int ty = y2;
			move(x2, y2, i);
			if (x2 < 0 || x2>7 || y2 < 0 || y2>7) {
				x2 = tx;
				y2 = ty;
				x1 = ox;
				y1 = oy;
			}
		}
	}
	cout << (char)(x1 + 'A') << y1 + 1 << "\n";
	cout << (char)(x2 + 'A') << y2 + 1 << "\n";
}