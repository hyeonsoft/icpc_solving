#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getNumber(string x) {
	const string w[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	for (int i = 0; i < 10; i++) {
		if (w[i] == x)return i;
	}
}

int main() {
	string a, b, c;
	long long int x;
	cin >> a >> b >> c;
	x=getNumber(a) * 10 + getNumber(b);
	x*=pow(10.0, (double)getNumber(c));
	cout << x;
}