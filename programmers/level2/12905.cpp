#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

// 가장 큰 정사각형 찾기
// DP 사용. 길이가 2인 정사각형 범위 내에서 확인하며 최솟값 + 1 갱신

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int N = board.size();
	int M = board[0].size();

	if (N == 1 || M == 1) return 1;

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (board[i][j] == 0) continue;

			board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
			answer = max(answer, board[i][j]);
		}
	}

	return answer * answer;
}