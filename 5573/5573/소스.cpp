#include <iostream>
int H, W, N;
int board[1000][1000];

using namespace std;

//±¸Çö
pair<int,int> solve() {
	int x = 0, y = 0;
	while (1) {
		if (x == W || y == H)break;
		if (board[x][y] == 0) {
			board[x][y] = 1;
			y++;
		}
		else {
			board[x][y] = 0;
			x++;
		}
	}
	return pair<int, int>{x + 1, y + 1};
}
int dptable[1000][1000]{ 0 };
void dp(int x, int y){
	int t = dptable[x][y];
	if (t == 0)return;
	int goright=t/2, godown=t/2;
	if(t%2){
		if (board[x][y] == 1) {
			goright++;
		}
		else {
			godown++;
		}
	}
	if (x < W - 1 )dptable[x + 1][y] += goright;
	if (y < H - 1 )dptable[x][y + 1] += godown;
}

int main() {
	cin >> H >> W >> N;
	for (int i = 0; i < H; i++) {
		for (int p = 0; p < W; p++) {
			cin >> board[p][i]; //x, yÁÂÇ¥
		}
	}
	dptable[0][0] = N - 1;
	for (int i = 0; i < W; i++) {
		for (int p = 0; p < H; p++) {
			dp(i, p);
		}
	}
	dptable[0][0] = N - 1;
	for (int x = 0; x < W; x++) {
		for (int y = 0; y < H; y++) {
			board[x][y] = (dptable[x][y] + board[x][y]) % 2;
		}
	}
	pair<int, int> ans = solve();


	cout << ans.second << " " << ans.first;
}