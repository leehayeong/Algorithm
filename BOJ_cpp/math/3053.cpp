#include <cstdio>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

// �ý� �����п��� ���� ������ ���. ���� = 2 * r * r
// ��Ŭ���� �����п��� ���� �� ���. ���� = pi * r * r

int main() {
	int r;
	scanf("%d", &r);

	double u, t;
	u = M_PI * r * r;
	t = 2 * r * r;

	printf("%.6f\n", u);
	printf("%.6f\n", t);

}