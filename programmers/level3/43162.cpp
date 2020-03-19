#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
네트워크 개수 return = bfs 호출 횟수
*/

bool checked[200];

void bfs(int n, int size, vector<vector<int>> computers){
    queue<int> q;
    q.push(n);
    checked[n] = true;
    
    while(!q.empty()){
        int cur_n = q.front();
        q.pop();
        
        for(int next_n = 0; next_n < size; next_n++){
            if(checked[next_n] == false && computers[cur_n][next_n] == 1){
                q.push(next_n);
                checked[next_n] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(checked[i] == false){
            bfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}