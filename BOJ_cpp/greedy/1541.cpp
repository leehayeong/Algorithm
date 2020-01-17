#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
잃어버린 괄호
양수, +, -, 괄호로 식을 만들고, 괄호를 모두 지웠다.
다시 괄호를 적절히 쳐서 값을 최소로 만들어라.

1. -가 가장 처음 나온 지점을 찾는다.
2. 다음 -가 나오기 전까지 모두 괄호로 묶어 + 계산을 한다.
3. 1로 돌아가서 -가 나오지 않을때까지 반복한다.
*/

char c;
string expr;
int first, second, sum;

int calSum(string s) {
	// 덧셈 계산
	int i, result = 0;
	while (true) {
		i = s.find('+');

		if (i == -1) {
			result += atoi(s.c_str());
			break;
		}

		result += atoi(s.substr(0, i).c_str());
		s = s.substr(i + 1);
	}

	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> expr;

	bool minus = false;
	while (true) {
		first = expr.find('-');
		second = expr.find('-', first + 1);
	
		// 식에 -가 없다면, 전체 식 계산하고 종료
		if (first == -1) {
			sum += calSum(expr);
			break;
		}

		// 식에 -가 한 개만 존재한다면 오른쪽 계산한 뒤 - 연산
		if (second == -1) {
			sum -= calSum(expr.substr(first + 1));
			
			// 단, 첫 부호가 -가 아니었다면 왼쪽 계산
			if (first != 0) {
				sum += calSum(expr.substr(0, first));
			}

			break;
		}

		// -가 또 존재한다면, 첫 계산 후(a-b) 계산한 이후로 식 잘라내어 같은 과정 반복
		sum += calSum(expr.substr(0, first));
		sum -= calSum(expr.substr(first + 1, second - first - 1));
		expr = expr.substr(second);
	}

	cout << sum;
}