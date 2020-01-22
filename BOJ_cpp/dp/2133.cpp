#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

int d[1001];

int dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];

	int tmp = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		if (x % 2 == 0) {
			tmp += 2 * dp(x - i);
		}
	}
	return d[x] = tmp;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << dp(n);
}