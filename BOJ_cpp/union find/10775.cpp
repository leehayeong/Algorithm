#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

/*
공항
비행기를 영구적으로 도킹할 수 있는 최대 수는?
*/

int G, P, cnt;
int parent[100001];

int findParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	parent[a] = b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> G >> P;

	// 초기화
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}

	// 도착 순서
	for (int i = 1; i <= P; i++) {
		int num;
		cin >> num;

		int max = findParent(num);
		if (max == 0) break;	// max가 0이면 더이상 도킹할 곳 X

		unionParent(max, max - 1);	// max에 도킹하고, 다음 도킹을 max-1에 하도록.
		cnt++;	// 도킹 완료
	}

	cout << cnt;
}