#include <cstdio>
#include <algorithm>

using namespace std;

// 직사각형에서 세 점을 주면, 나머지 한 점이 어디인지 찾기

int main() {
	int rect[3][2];
	int dx, dy;
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &rect[i][0], &rect[i][1]);
	}

	// 공통으로 존재하는 x, y 찾고
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			if (rect[i][0] == rect[j][0]) {
				dx = rect[i][0];
			}

			if (rect[i][1] == rect[j][1]) {
				dy = rect[i][1];
			}
		}
	}

	// 세 점 중 공통을 존재하는 x, y를 제외한 값을 갖는 점 나머지 점
	int rx, ry;
	for (int i = 0; i < 3; i++) {
		if (rect[i][0] != dx) rx = rect[i][0];
		if (rect[i][1] != dy) ry = rect[i][1];
	}

	printf("%d %d", rx, ry);
}