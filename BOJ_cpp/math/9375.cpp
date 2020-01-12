#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

/*
패션왕 신혜빈
의상 수 n / 의상 이름과 종류 
종류별 가진 옷의 개수 + 1(안입는 경우의 수)를 모두 곱한 뒤, 알몸인 상태인 1을 빼준다.
*/

int t;
int n;				// 의상 수
map<string, int> m;	// 의상 분류, 개수

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	
	while (t--){
		cin >> n;
		m.clear();

		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;

			m[type]++;
		}

		long long mul = 1;
		map<string, int>::iterator i;
		for (i = m.begin(); i != m.end(); i++) {
			mul *= (long long)i->second + 1;
		}

		cout << mul - 1 << "\n";
	}
}