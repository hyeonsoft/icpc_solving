#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

//union find
int tree[200001];
int parent[200001];
int find(int tree) {
	if (parent[tree] == tree)return tree;//tree가 부모일 때
	return parent[tree] = find(parent[tree]);
}
bool merge(int mother, int son) {
	if(mother)
}