#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

/*
스타트와 링크
N/2명인 스타트팀과 링크팀을 나누려고 한다.
두 팀의 능력 차이를 최소로 하는 팀을 구성할 때, 두 팀의 차이는?
*/

int N, tsize;
int map[20][20];
int checked[20], schecked[20];
vector<int> startTeam, linkTeam;
int startSum, linkSum;
int ans = 1000000000;

// 2명씩 능력치 구해 더하기
int calSum(vector<int> v, int idx, int cnt, int sum) {
	if (cnt == 2) return sum;

	int ret = 0;
	for (int i = idx; i < tsize; i++) {
		int n1 = v[idx], n2 = v[i];
		if (schecked[n2] == false) {
			schecked[n2] = true;
			ret += calSum(v, i, cnt + 1, map[n1][n2] + map[n2][n1]);
			schecked[n2] = false;
		}
	}

	return ret;
}

// 스타트 팀 구성
void dfs(int idx, int cnt) {
	// 스타트 팀 인원배정이 끝나면 링크팀 구성
	if (cnt == tsize) {
		for (int i = 0; i < N; i++) {
			if (checked[i] == false) {
				linkTeam.push_back(i);
			}
		}

		// 팀원 능력 구하기		
		startSum += calSum(startTeam, 0, 0, 0);
		memset(schecked, false, sizeof(schecked));
		linkSum += calSum(linkTeam, 0, 0, 0);

		// 최솟값 갱신
		ans = min(ans, abs(startSum - linkSum));

		// 케이스 한 개 계산 끝나면 모두 초기화
		linkTeam.clear();
		startSum = 0; linkSum = 0;
		return;
	}

	// 스타트팀 모든 조합 구하기
	for (int i = idx + 1; i < N; i++) {
		if (checked[i] == false) {
			checked[i] = true;
			startTeam.push_back(i);
			dfs(i, cnt + 1);
			checked[i] = false;
			startTeam.pop_back();
		}
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	tsize = N / 2;

	dfs(0, 0);
	cout << ans;
}