#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int t;
	cin >> t;
	while (t--) {
		string x, y;
		cin >> x;
		cin >> y;
		int z = 0;
		for (int i = 0; i < x.size(); i++) {
			if (x[i] != y[i])z++;
		}
		cout << "Hamming distance is " << z << ".\n";
	}
	return 0;
}