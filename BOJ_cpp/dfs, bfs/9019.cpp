#include <iostream> 
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

/*
DSRL
A->B 로 변환하기 위한 최소 명령어모음은?

D: 2배	if(2n > 9999) 2n = 2n % 10000
S: -1	if(n == 0) n = 9999; else n = n - 1;
L: 왼쪽회전		n = ((n % 10) * 1000) + (n / 10)
R: 오른쪽회전	n = ((n % 1000) * 10) + (n / 1000)
*/

typedef struct {
	int n;
	string cmd;
}num;

int T, A, B;
bool visited[10000];
char cmds[4] = { 'D', 'S', 'L', 'R' };

string bfs() {
	queue<num> q;		// 수, 누적명령어 pair

	q.push({ A, "" });
	visited[A] = true;

	while (!q.empty()) {
		num cur_num = q.front();
		int cur_n = cur_num.n;
		string cur_cmd = cur_num.cmd;
		q.pop();

		for (int i = 0; i < 4; i++) {
			char cmd = cmds[i];
			int next_n = 0;
			string next_cmd = cur_cmd + cmd;

			if (cmd == 'D') {
				if (cur_n * 2 > 9999) next_n = (cur_n * 2) % 10000;
				else next_n = cur_n * 2;
			}
			else if (cmd == 'S') {
				if (cur_n == 0) next_n = 9999;
				else next_n = cur_n - 1;
			}
			else if (cmd == 'L') {
				next_n = ((cur_n % 1000) * 10) + (cur_n / 1000);
			}
			else if (cmd == 'R') {
				next_n = ((cur_n % 10) * 1000) + (cur_n / 10);
			}

			if (next_n == B) return next_cmd;

			if (visited[next_n] == false) {
				q.push({ next_n, next_cmd });
				visited[next_n] = true;
			}
		}
	}

	return "";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << bfs() << "\n";
		memset(visited, false, sizeof(visited));
	}
}