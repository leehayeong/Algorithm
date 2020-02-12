#include <iostream> 
#include <deque>
#include <string>
using namespace std;

/*
AC언어
함수R 뒤집기
함수D 가장 앞 원소 삭제
*/

string p, s;
int N;
deque<int> deq;
bool error, rev;

// [x1, ... , xn]과 같은 형태로 주어진다. 
// ','를 기준으로 나누어 배열에 저장한다.
void input(string tmp) {
	int length = tmp.length();
	
	int num = tmp[1] - '0';
	for (int i = 2; i < length; i++) {
		if (tmp[i] >= '0' && tmp[i] <= '9') {
			if (num == -1) {
				num = tmp[i] - '0';
			}
			else {
				num = num * 10 + (tmp[i] - '0');

			}
		}
		else {
			deq.push_back(num);
			num = -1;
		}
	}
}

void output() {
	cout << "[";
	while (!deq.empty()) {
		if (!rev) {
			cout << deq.front();
			deq.pop_front();
		}
		else {
			cout << deq.back();
			deq.pop_back();
		}

		if (!deq.empty()) cout << ",";
	}
	cout << "]\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> p >> N >> s;

		// 초기화하고, 원소의 개수가 0이 아니라면 입력받는다.
		deq.clear();
		rev = false;
		error = false;
		if (N != 0) input(s);

		int length = p.length();
		for (int i = 0; i < length; i++) {
			char func = p[i];

			// 함수 R = 배열의 순서를 뒤집는다.
			if (func == 'R') {
				rev = !rev;
			}

			// 함수 D = 첫 번째 숫자를 버린다.
			else if (func == 'D') {
				if (deq.empty()) {
					error = true;
					cout << "error\n";
					break;
				}

				if (rev) deq.pop_back();
				else deq.pop_front();
			}
		}
	
		// 결과를 출력한다.
		if (!error) output();
	}
}