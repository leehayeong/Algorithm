#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define RANGE 10
int N;
int map[101][101];
vector<pair<int, int>> curve;

// 사각형 개수 세기
int count() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			// 1이 나오면 우/우하/하 모두 1인지 검사
			if (map[i][j] == 1) {
				if (map[i][j + 1] == 1 && map[i + 1][j + 1] == 1 && map[i + 1][j] == 1) cnt++; 
			}
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		// 입력
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		swap(x, y);
		map[x][y] = 1;
		curve.push_back(make_pair(x, y));

		int ex = x, ey = y;			// 끝 점
		int nex = ex, ney = ey;		// 다음 끝 점
				
		// 0세대
		if (d == 0) {
			map[x][y + 1] = 1;	// →
			ey = y + 1;
		}
		else if (d == 1) {
			map[x - 1][y] = 1;	// ↑
			ex = x - 1;
		}
		else if (d == 2) {
			map[x][y - 1] = 1;	// ←
			ey = y - 1;
		}
		else if (d == 3) {
			map[x + 1][y] = 1;	// ↓
			ex = x + 1;
		}
		
		// g세대 드래곤커브
		for (int j = 1; j <= g; j++) {
			// 회전시켜야 할 점들의 개수를 미리 세고, 기준 점 저장
			int size = curve.size();
			curve.push_back(make_pair(ex, ey));

			for (int k = 0; k < size; k++) {
				int cx = curve[k].first;
				int cy = curve[k].second;

				// x만큼 차이가 끝점으로부터 y차이, 
				// y만큼 차이가 끝점으로부터 x차이가 됨.
				int dx = cx - ex;
				int dy = cy - ey;

				cx = ex + dy;
				cy = ey - dx;
				map[cx][cy] = 1;

				// 가장 먼저 회전한 점이 다음 경우에서 끝 점이 됨
				if (k == 0) {
					nex = cx; ney = cy;
				}
				// 회전시킨 점들도 저장
				else {
					curve.push_back(make_pair(cx, cy));
				}
			}

			// 끝 점 갱신
			ex = nex, ey = ney;
		}
		curve.clear();
	}

	// 정사각형 개수 세기
	cout << count();
}