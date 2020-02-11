#include <iostream> 
#include <deque>
using namespace std;

int N, M, cnt;
deque<int> deq;

// x번째 수를 바로 뽑을 수 있는지?
bool isPossible(int x) {
	if (deq.front() == x) {
		deq.pop_front();
		return true;
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	// 원형 큐 생성
	for (int i = 1; i <= N; i++) {
		deq.push_back(i);
	}

	// 뽑기 시작
	for(int k = 0; k < M; k++){
		int x;
		cin >> x;

		// 바로 뽑을 수 있을 때까지, 반복
		while (!isPossible(x)) {

			// 이동이 필요하다면 최소 이동 횟수 구하기
			int size, index, tmp;
			size = N - k;

			// 1. front에 가까운지 back에 가까운지 계산하기 위해 인덱스 찾기
			for (int i = 0; i < size; i++) {
				if (deq[i] == x) {
					index = i;
					break;
				}
			}

			// 2. 인덱스가 front에 가깝다면 2번 연산
			if (index <= size / 2) {
				tmp = deq.front();
				deq.pop_front();
				deq.push_back(tmp);
			}

			// 3. 인덱스가back에 가깝다면 3번 연산
			else {
				tmp = deq.back();
				deq.pop_back();
				deq.push_front(tmp);
			}

			cnt++;
		}
	}

	cout << cnt;
}