//https://www.acmicpc.net/problem/1182

#include <iostream>
#include <vector>

using namespace std;

int gets=0;
int b;

vector <int> list;

void find(int u,int sum) {
	if (sum + list[u] == b) {
		gets++;
	}
	if (u+1 < list.size())find(u + 1, list[u] + sum);
	if(u+1<list.size())find(u + 1, sum);
}

int main() {
	int a;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
	}
	find(0, 0);
	cout << gets;
}