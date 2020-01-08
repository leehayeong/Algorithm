#include <cstdio>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

// 택시 기하학에서 원은 마름모 모양. 넓이 = 2 * r * r
// 유클리드 기하학에서 원은 원 모양. 넓이 = pi * r * r

int main() {
	int r;
	scanf("%d", &r);

	double u, t;
	u = M_PI * r * r;
	t = 2 * r * r;

	printf("%.6f\n", u);
	printf("%.6f\n", t);

}