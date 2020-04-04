#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

/*
가장 먼 노드
1번노드부터 가장 먼 노드의 갯수는?
*/

int map[20001][20001];
int dist[20001];        // 1번부터 거리

void bfs(int start, int n){
    queue<int> q;       // 출발지
    q.push(start);
    dist[start] = 0;
    
    // 다음 출발지로 가면서 거리 갱신 (최소가 되도록)
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next = 1; next <= n; next++){
            if(map[cur][next] == 1 && (dist[next] == -1 || dist[next] > dist[cur] + 1)){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++){
        map[edge[i][0]][edge[i][1]] = 1;
        map[edge[i][1]][edge[i][0]] = 1;
    }
    
    // BFS
    memset(dist, -1, sizeof(dist));
    bfs(1, n);
    
    // 최댓값과 개수 동시에 구함
    int maxVal = 0;
    for(int i = 1; i <= n; i++){
        if(maxVal == dist[i]) {
            answer++;
        } else if (maxVal < dist[i]){
            maxVal = dist[i];
            answer = 1;
        }
    }

    return answer;
}