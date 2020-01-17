#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
�Ҿ���� ��ȣ
���, +, -, ��ȣ�� ���� �����, ��ȣ�� ��� ������.
�ٽ� ��ȣ�� ������ �ļ� ���� �ּҷ� ������.

1. -�� ���� ó�� ���� ������ ã�´�.
2. ���� -�� ������ ������ ��� ��ȣ�� ���� + ����� �Ѵ�.
3. 1�� ���ư��� -�� ������ ���������� �ݺ��Ѵ�.
*/

char c;
string expr;
int first, second, sum;

int calSum(string s) {
	// ���� ���
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
	
		// �Ŀ� -�� ���ٸ�, ��ü �� ����ϰ� ����
		if (first == -1) {
			sum += calSum(expr);
			break;
		}

		// �Ŀ� -�� �� ���� �����Ѵٸ� ������ ����� �� - ����
		if (second == -1) {
			sum -= calSum(expr.substr(first + 1));
			
			// ��, ù ��ȣ�� -�� �ƴϾ��ٸ� ���� ���
			if (first != 0) {
				sum += calSum(expr.substr(0, first));
			}

			break;
		}

		// -�� �� �����Ѵٸ�, ù ��� ��(a-b) ����� ���ķ� �� �߶󳻾� ���� ���� �ݺ�
		sum += calSum(expr.substr(0, first));
		sum -= calSum(expr.substr(first + 1, second - first - 1));
		expr = expr.substr(second);
	}

	cout << sum;
}