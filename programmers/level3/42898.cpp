#include <string>
#include <vector>

using namespace std;

/*
등굣길
최단거리로 가기 위해서는 오른쪽 and 아래방향으로만 가야 함
현재 경로 개수 = 위, 왼쪽에서 온 경로 개수의 합
*/

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    // 범람지역 표시
    for(int i = 0; i < puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    dp[1][1] = 1;   // 출발지
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            if(r == 1 && c == 1) continue;  // [1][1]은 출발지이므로 pass
            
            if(dp[r][c] == -1) {
                dp[r][c] = 0;               // 물웅덩이면 경로 0이므로 update
            }
            else {
                dp[r][c] = (dp[r-1][c] + dp[r][c-1]) % 1000000007;
            }
        }
    }
    
    answer = dp[n][m];
    return answer;
}