#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
집합의 표현
N = 노드 수, M = 연산의 개수
0 = 합집합, 1 = 두 원소가 같은 집합에 포함되어 있는가?
*/

int N, M;
int parent[1000001];

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
	
	// 부모 배열 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	// union-find 
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> c >> a >> b;
	
		if (c == 0){	// 합집합 연산
			unionParent(a, b);
		}
		else if (c == 1) { // 같은 부모? 
			if (findParent(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}	
	}
}