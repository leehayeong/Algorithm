#include <cstdio>
#include <algorithm>

using namespace std;

/*
���μ����� �ϴ� ���α׷�
= ��� ��� ���ϱ�(�ߺ��ؼ�)
*/

int n;

int main() {
	scanf("%d", &n);

	int idx = 2;
	while (n > 1) {
		for (int i = idx; i <= n; i++) {
			// n�� i�� ����������, ����̹Ƿ� ����ϰ�
			// ���� ���μ��� ã�� ����
			// n�� ������ �����ϰ�, �������� i�� ����
			if (n % i == 0) {
				printf("%d\n", i);
				n = n / i;
				idx = i;
				break;
			}
		}
	}
}