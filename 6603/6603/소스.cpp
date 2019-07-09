#include <iostream>
#include <set>

using namespace std;

set<int> *lists = NULL;
set<set<int>> *cnt = NULL;

void make(int t, int depth, int nowcnt, set<int> num) {
	if (t == depth)return;
	if (nowcnt == 6) {
		cnt->insert(num);
		return;
	}
	for (int i = 1; i >= 0; i--) {
		num.insert(*(int*)&lists[depth]);
		make(t, depth + 1, nowcnt + i, num);
	}
}

int main() {
	while (1) {
		int t;
		cin >> t;
		if (t == 0)return 0;
		lists = new set<int>{};
		cnt = new set < set<int> > ();
		for (int i = 0; i < t; i ++ ) {
			int in;
			cin >> in;
			lists->insert(in);
		}

		make(t, 0, 0, set<int>{});
		
		for (auto it = cnt->begin();it!=cnt->end(); it++) {
			set<int> a = *it;
			for (auto a=it->begin();a!=it->end(); a++) {
				cout << *a << " ";
			}
		}

		cout << "\n";
		delete cnt;
		delete lists;
	}
}