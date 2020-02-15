#include <iostream> 
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
반복수열
D[1] = A
D[n] = D[n-1]의 각 자리의 숫자를 P번 곱한 수들의 합
1 <= A <= 9999, 1 <= P <= 5 이므로d
9999 5 입력했을 때 D[1] = 236196 = 6자리 수
배열 최대 크기 1000000 으로
*/

int A, P, v_max;
int num[1000000];

int mulSum(int x) {
	int sum = 0;
	while (x > 0) {
		int t = x % 10;
		sum += pow(t, P);
		x = x / 10;
	}
	return sum;
}

void dfs(int a) {
	num[a]++;
	if (v_max < a) v_max = a;

	if (num[a] == 3) return;
	
	dfs(mulSum(a));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> P;

	dfs(A);

	int cnt = 0;
	for (int i = 1; i <= v_max; i++) {
		if (num[i] == 1) {
			cnt++;
		}
	}

	cout << cnt;
}