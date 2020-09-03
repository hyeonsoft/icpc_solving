#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int x, y, d, t;

int main() {
	
	cin >> x >> y >> d >> t;
	if (d/t==0) {
		cout.precision(20);
		cout << sqrt((double)x*x + y * y);
	}
	else {
		double distance = sqrt(x*x + y * y);
		double t1 = (double)((int)(distance / d))*t + distance - (double)d * ((int)(distance / d));
		double t2= (double)((int)(distance / d)+1)*t;
		if ((int)(distance / d) == 0) {
			t2 = t - distance + d;
			t2 = min(t2, (double)t * 2);
		}
		double t3 = distance;
		cout.precision(20);
		cout << min(min(t1, t2), t3);
	}
}