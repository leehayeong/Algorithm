#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

long long d[100];

long long fib(long long x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (d[x] != 0) return d[x];
	return d[x] = fib(x - 1) + fib(x - 2);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << fib(n);
}