#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

/*
피보나치를 구현했을 때, 0과 1이 호출되는 수
*/

long long d[41][2];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t, n;
	
	// 0일 때 0의 개수는 1, 1의 개수는 0
	d[0][0] = 1;
	d[0][1] = 0;

	// 1일 때 0의 개수는 0, 1의 개수는 1
	d[1][0] = 0;
	d[1][1] = 1;

	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 2; i <= n; i++) {
			d[i][0] = d[i - 1][0] + d[i - 2][0];
			d[i][1] = d[i - 1][1] + d[i - 2][1];
		}
		
		cout << d[n][0] << " " << d[n][1] << "\n";
	}
}