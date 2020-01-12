#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
���丮�� 0�� ����
���ڸ����� 0�� �ƴ� ���� ���ö����� 0�� ����
��) 10! = 3628800 -> ���� = 2
*/

int n, five, two, tmp;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	// 0�� ������ ���ؼ��� 5*2 �� �ݵ�� ���ԵǾ�� �Ѵ�.
	// ��, 5*2�� ���μ��� �����ϸ�, �� ���� ������ �����̴�.
	// ���丮���̹Ƿ� 2���� n���� ���μ��� ���Ѵ�.
	for (int i = 2; i <= n; i++) {
		tmp = i;
		while (tmp % 5 == 0) {
			five++;
			tmp = tmp / 5;
		}
		while (tmp % 2 == 0) {
			two++;
			tmp = tmp / 2;
		}
	}

	cout << min(five, two);
}