#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int b[20][20];

void bfs

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int p = 0; p < N; p++) {
			int a;
			cin >> a;
			b[i][p]=(a=='E'?0:1);
		}
	}

}