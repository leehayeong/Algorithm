#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

/*
비용을 저장할 배열 (행 n, 열 0=R, 1=G, 2=B)

이웃집과 겹치지 않는 색 중 최소 비용을 더해가기
*/

int rgb[1001][3];
int cost[1001][3];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	cost[1][0] = rgb[1][0];
	cost[1][1] = rgb[1][1];
	cost[1][2] = rgb[1][2];
	for (int i = 2; i <= n; i++) {
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + rgb[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + rgb[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + rgb[i][2];
	}

	cout << min(min(cost[n][0], cost[n][1]), cost[n][2]);
}