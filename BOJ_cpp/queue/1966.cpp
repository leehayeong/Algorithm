#include <iostream> 
#include <list>
#include <vector>
using namespace std;

int T, N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> T;
	while (T--) {
		cin >> N >> M;
		list<pair<int, int>> q;
		vector<int> result;

		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			q.push_back(make_pair(i, x));
		}

		while (!q.empty()) {
			bool flag = false;
			pair<int, int> val = q.front();

			list<pair<int, int>>::iterator it;
			for (it = q.begin(); it != q.end(); it++) {
				if (val.second < it->second) {
					flag = true;
					break;
				}
			}

			// 나보다 중요도가 큰 문서가 있으면 가장 뒤로
			if (flag) {
				q.pop_front();
				q.push_back(val);
			}
			// 아니면 출력하고, 순서를 알아보기 위해 결과 배열에 삽입
			else {
				q.pop_front();
				result.push_back(val.first);
			}
		}

		// 결과 출력 (index가 몇 번째 출력인지 순서, 내용물이 자료 A B C ... )
		for (int i = 0; i < N; i++) {
			if (result[i] == M) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}
}