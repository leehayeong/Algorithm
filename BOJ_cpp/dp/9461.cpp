#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

/*
점화식
d[n] = d[n-1] + d[n-5]
*/

long long d[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	long long t, n;

	d[0] = 0, d[1] = 1, d[2] = 1, d[3] = 1, d[4] = 2;
	for (long long i = 5; i <= 100; i++) {
		d[i] = d[i - 1] + d[i - 5];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << d[n] << "\n";
	}
}