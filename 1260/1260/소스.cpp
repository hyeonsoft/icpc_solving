#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, v;
int graph[1000][1000];
int isvisited1[1000]{ 0 };
int isvisited2[1000]{ 0 };
queue<int> BFS_queue;

void letsfind_DFS(int node) {
	isvisited1[node] = 1;
	cout << node+1 << " ";
	for (int i = 0; i < n; i++) {
		if (graph[node][i]==1&&!isvisited1[i]) {
			letsfind_DFS(i);
		}
	}
}

void letsfind_BFS() {
	while (BFS_queue.size()) {
		if (isvisited2[BFS_queue.front()] == 0) {
			isvisited2[BFS_queue.front()] = 1;
			cout << BFS_queue.front()+1<<" ";
		}
		for (int i = 0; i < n; i++) {
			if (graph[BFS_queue.front()][i] == 1 && !isvisited2[i]) {
				cout << i+1 << " ";
				BFS_queue.push(i);
				isvisited2[i] = 1;
			}
		}
		BFS_queue.pop();
	}
}

int main() {
	memset(graph, -1, sizeof(graph));
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	letsfind_DFS(v - 1);
	cout << "\n";
	BFS_queue.push(v - 1);
	letsfind_BFS();
}