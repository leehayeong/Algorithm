#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	long long x, y;
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> x >> y;
		long long dis = y - x;
		long long n, remain, cnt;

		for (n = 1; n * n < dis; n++); 
		cnt = n * 2 - 1;

		remain = dis - n * n;

		// why???????
		cnt += (long long)ceil((double)remain / (double)n);
		cout << cnt << "\n";		
	}
}

/*
1 2 3 2 1 -> 합은 3^2. 대칭을 만드는 수가 n
n^2이 거리의 차보다 커질 때, 그 직전의 n을 구한다.
그리고 거리에서 합을 뺀 나머지 거리를 몇 번 거쳐야하는지 구한다. (여기서 몫과 올림 연산은 왜 사용?
*/

/*
while (true) {
	for (n = 1; n * n < remain; n++);
	if(n > 1) n--;
	//n = (int)sqrt(remain);
	remain = remain - n * n;
	if (remain == 0) {
		cnt += n;
		break;
	}
	cnt++;
}
*/