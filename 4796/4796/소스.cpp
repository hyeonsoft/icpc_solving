#include <iostream>

using namespace std;

int l, p, v, i;

int main() {
	cin >> l >> p >> v;
	if (l == 0 && p == 0 && v == 0)return 0;
	cout << "Case " << ++i << ": " << v/p*l+(v%p>l?l:v%p) <<"\n";
	main();
}