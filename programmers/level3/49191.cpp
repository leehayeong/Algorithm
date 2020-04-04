#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
순위
나보다 쎈 사람 수 + 나보다 약한 사람 수 = n-1이 되어야 순위를 정확히 할 수 있음
*/

int winner[101][101];   // 이긴 사람들과의 관계
int loser[101][101];    // 진 사람들과의 관계
bool checked[101][101]; // 이겼는지 졌는지 체크
int counts[101];        // 몇 명과의 승패가 정해졌는지

// BFS를 돌면서 나(start)와 승패가 정해진 사람의 수를 count
void bfs(int map[101][101], int start, int n){
    queue<int> q;
    q.push(start);
    int cnt = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next = 1; next <= n; next++){
            if(map[cur][next] == 1 && checked[start][next] == false){
                cnt++;
                q.push(next);
                checked[start][next] = true;
            }
        }
    }
    
    counts[start] += cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 0; i < results.size(); i++){
        winner[results[i][0]][results[i][1]] = 1;
        loser[results[i][1]][results[i][0]] = 1;
    }
    
    // 각 선수를 출발점으로 BFS
    for(int i = 1; i <= n; i++){
        bfs(winner, i, n);
        bfs(loser, i, n);
    }
    
    // n-1 사람과의 승패가 정해졌다면 순위가 매겨짐
    for(int i = 1; i <= n; i++){
        if(counts[i] == n - 1) answer++;
    }
    
    return answer;
}