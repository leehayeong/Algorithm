#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
여행 가자
주어진 여행 계획이 가능한지 판별 = 여행 계획에 속한 도시들이 이어져 있는지?
도시 수 N, 여행 계획에 속한 도시 수 M
*/

int N, M;
int parent[201];
int plan[1001];

int getParent(int a) {
	if (parent[a] == a) return parent[a];
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	// union
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int val;
			cin >> val;
			if (val == 1) {	// 연결되어 있으면 합집합 수행
				unionParent(i, j);
			}
		}
	}

	// find
	for (int i = 1; i <= M; i++) {
		cin >> plan[i];
	}
	for (int i = 1; i <= M - 1; i++) {
		// 부모가 같지 않으면 = 연결되어 있지 않으면 여행 불가.
		if (findParent(plan[i], plan[i + 1]) == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}