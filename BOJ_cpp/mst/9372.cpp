#include <iostream> 

using namespace std;

/*
상근이의 여행
비행 스케줄이 주어졌을 때, 모든 도시를 여행하기 위해 타야하는 비행기 종류의 최소 개수?
*/

int N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1 << "\n";
	}
}