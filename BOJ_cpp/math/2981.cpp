#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
�˹�
���� n���� ���̿� ����, m���� �������� ��
�������� ��� ���ԵǴ� m�� ��� ã�ƶ�.

num[i] = M * ��1 + ������
���⼭ �������� �������� �ٸ� ���� ���� �� �������� ������� �Ѵ�.
num[i+1] = M * ��2 + ������

num[i] - num[i+1] = M * (��1 - ��2)

3, 19, 27�� ��
19 = 8 * 2 + 3
27 = 8 * 3 + 3
���⼭ 8�� �ִ����� 
M�� �ִ������� ��� (1 ����) = 2, 4, 8
*/

int n;
long long m;
long long num[100];
vector<long long> v;

long long gcd(long long x, long long y) {
	int a, b, c;
	a = x;
	b = y;

	while (true) {
		c = a % b;

		if (c == 0) break;

		a = b;
		b = c;
	}

	return b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	
	// �Է¹��� ��� ���� ������ �ִ����� ���ϱ�
	m = num[1] - num[0];
	for (int i = 2; i < n; i++) {
		m = gcd(num[i] - num[i - 1], m);
	}

	// ���� �ִ������� ���
	int i;
	for (i = 2; i * i < m; i++) {
		if (m % i == 0) {
			v.push_back(i);		// ���
			v.push_back(m / i);	// ���� �̷�¾��
		}
	}
	if (i * i == m) v.push_back(i);
	v.push_back(m);

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}