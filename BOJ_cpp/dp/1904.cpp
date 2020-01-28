#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

/*
점화식
d[n] = d[n-1] + d[n-2]
*/

long long d[1000001];

long long func(long long n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (d[n] != 0) return d[n];
	return d[n] = (func(n - 1) + func(n - 2)) % 15746;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	long long n;

	cin >> n;
	cout << func(n);
}