#include <iostream>
#include <vector>

using namespace std;
int fb[] = { 1, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 5, 5, 8, 8, 13, 13, 21, 21, 34, 34, 55, 55, 89, 89, 144, 144, 233, 233, 377, 377, 610, 610, 987, 987, 1597, 1597, 2584, 2584, 4181, 4181, 6765, 6765, 10946, 10946, 17711, 17711, 28657, 28657, 46368, 46368, 75025, 75025, 121393, 121393, 196418, 196418, 317811, 317811, 514229, 514229, 832040, 832040, 1346269, 1346269, 2178309, 2178309, 3524578, 3524578, 5702887, 5702887, 9227465, 9227465, 14930352, 14930352, 24157817, 24157817, 39088169, 39088169, 63245986, 63245986, 102334155 }
;
int main() {
	int a;
	cin >> a;
	while (a--) {
		int k;
		cin >> k;
		cout << fb[k * 2] << " " << fb[k * 2 + 1] << "\n";
	}
}

/*
vector <long long int> fb;

int a, b;

int fibonacci(int n) {
	if (n == 0) {
		a++;
		return 0;
	}
	else if (n == 1) {
		b++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	for(int i=0;i<=40;i++){
		int k = i;
		a = 0; b = 0;
		fibonacci(k);
		cout << a << "," << b << ",";
	}
}

*/