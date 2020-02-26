#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

/*
친구 네트워크
친구 관계가 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지?
*/

int T, F;
int parent[200002], cnt[200002];
map<string, int> m;	// string 을 int 로 매칭
string cur;

int getParent(int a) {
	if (parent[a] == a) return parent[a];
	return parent[a] = getParent(parent[a]);
}

int unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {
		parent[b] = a;
		cnt[a] += cnt[b];
		cnt[b] = 1;
	}
	return cnt[a];
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> F;

		// 적어도 관계 수 * 2 개의 배열 초기화
		for (int i = 1; i <= F * 2; i++) {
			parent[i] = i;
			cnt[i] = 1;
		}

		int index = 1;
		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;

			// string 에 index 매핑
			if (m[a] == 0) m[a] = index++;
			if (m[b] == 0) m[b] = index++;

			// 합집합
			cout << unionParent(m[a], m[b]) << "\n";
		}

		m.clear();
	}
}