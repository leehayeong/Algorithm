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
1 2 3 2 1 -> ���� 3^2. ��Ī�� ����� ���� n
n^2�� �Ÿ��� ������ Ŀ�� ��, �� ������ n�� ���Ѵ�.
�׸��� �Ÿ����� ���� �� ������ �Ÿ��� �� �� ���ľ��ϴ��� ���Ѵ�. (���⼭ ��� �ø� ������ �� ���?
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