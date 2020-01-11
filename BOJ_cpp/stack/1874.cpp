#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

/*
push는 1부터 n까지 오름차순으로 한다.
임의의 수열을 스택을 이용해 만들 수 있다면
push는 +, pop은-, 만들 수 없다면 no를 출력하라.
*/

int main() {
	int n, arr[100001];
	stack<int> s;
	vector<char> op;
	string input = "", result = "";

	// 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		input += to_string(arr[i]);
	}

	// 1부터 n까지 push.
	// 현재 스택의 top이 arr[i]보다 작다면, arr[i] 수까지 push
	// 현재 스택의 top이 arr[i]보다 크다면, pop. (arr[i]보다 작아질때까지)
	for (int k = 1, i = 0; i < n;) {
		if (s.empty() || s.top() < arr[i]) {
			s.push(k);
			op.push_back('+');
			k++;
		}
		else if (s.top() >= arr[i]) {
			result += to_string((s.top()));
			s.pop();
			op.push_back('-');
			i++;
		}
	}

	// pop하면서 만들어진 string인 result와
	// 초기 입력 string인 input을 비교하여 같다면 연산자 출력
	if (result != input) cout << "NO\n";
	else {
		for (int i = 0; i < op.size(); i++) {
			cout << op[i] << "\n";
		}
	}
}