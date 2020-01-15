#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
���� n����, �ݾ� k
�ݾ��� ����� ���������� �ּڰ�
*/

int n, num[10], cnt;
long long k;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int i = n - 1;
	while (true) {
		// ��� ������ �ִ� ȭ�� ���� ã��
		// 4200 ������ 1000
		while (k / num[i] <= 0) i--;

		// num[i] = 1000
		// cnt = 4;
		// ��� ȭ�� ���� ���ϱ�
		cnt += k / num[i];

		// k = 4200 - 4 * 1000 = 200
		// ���� �ݾ� ���
		k = k - (k / num[i]) * num[i];

		if (k == 0) break;
	}

	cout << cnt;
}