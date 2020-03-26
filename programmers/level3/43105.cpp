#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 정수삼각형

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501];
    
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];
            else if (j == triangle[i].size() - 1) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    // max는 마지막행, 마지막열 원소들 중 최댓값
    int r = triangle.size() - 1;
    for(int c = 0; c < triangle[r].size(); c++){
        answer = max(answer, dp[r][c]);
    }
    
    return answer;
}