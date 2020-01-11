#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

/*
push�� 1���� n���� ������������ �Ѵ�.
������ ������ ������ �̿��� ���� �� �ִٸ�
push�� +, pop��-, ���� �� ���ٸ� no�� ����϶�.
*/

int main() {
	int n, arr[100001];
	stack<int> s;
	vector<char> op;
	string input = "", result = "";

	// �Է�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		input += to_string(arr[i]);
	}

	// 1���� n���� push.
	// ���� ������ top�� arr[i]���� �۴ٸ�, arr[i] ������ push
	// ���� ������ top�� arr[i]���� ũ�ٸ�, pop. (arr[i]���� �۾���������)
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

	// pop�ϸ鼭 ������� string�� result��
	// �ʱ� �Է� string�� input�� ���Ͽ� ���ٸ� ������ ���
	if (result != input) cout << "NO\n";
	else {
		for (int i = 0; i < op.size(); i++) {
			cout << op[i] << "\n";
		}
	}
}