#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
���� 0�� ����
���ڸ����� 0�� �ƴ� ���� ���ö����� 0�� ����
nCm = n! / m! (n-m)!

0�� ������ ���ؼ��� 5*2 �� �ݵ�� ���ԵǾ�� �Ѵ�.
��, 5*2�� ���μ��� �����ϸ�, �� ���� ������ �����̴�.

�Է� ���� �ſ� ũ�� ������ ���μ��� �� ã�°��� ��ȿ�����̴�.
n�� 2�� 5�� ��������
m�� 2�� 5�� ����, (n-m)�� 2�� 5�� ������ ���� ������� �ذ��Ѵ�. (�������Ƿ�)
*/

long long n, m;
int two, five;	

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	// n�� 2�� 5�� ���� (�ſ� ū ���̹Ƿ� ����� ������ Ȯ���Ѵ�.)
	for (long long i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		five += n / i;
	}

	// m�� 2�� 5�� ���� ����
	for (long long i = 2; i <= m; i *= 2) {
		two -= m / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		five -= m / i;
	}

	// n-m�� 2�� 5�� ���� ����
	for (long long i = 2; i <= n - m; i *= 2) {
		two -= (n - m) / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		five -= (n - m) / i;
	}

	cout << min(two, five);
}