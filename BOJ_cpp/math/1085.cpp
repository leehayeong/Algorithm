#include <cstdio>
#include <algorithm>

using namespace std;

// 한수 x, y, 사각형 가로 w, 높이 h

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int dir[4];
	dir[0] = x;
	dir[1] = y;
	dir[2] = w - x;
	dir[3] = h - y;
	printf("%d", min(min(dir[0], dir[2]), min(dir[1], dir[3])));

}