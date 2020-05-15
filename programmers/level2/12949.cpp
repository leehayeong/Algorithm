#include <string>
#include <vector>

using namespace std;

// 행렬의 곱셈 (AXB * BXC = AXC)

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	int A = arr1.size();
	int B = arr1[0].size();
	int C = arr2[0].size();
	vector<vector<int>> answer(A, vector<int>(C));  // 결과 배열은 AXC 크기

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < B; k++) {
				answer[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	return answer;
}