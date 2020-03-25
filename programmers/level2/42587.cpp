#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
프린터
우선순위에 따라 인쇄되는 순서는?
*/

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> orders(priorities.size(), 0);    // 인쇄 순서 저장
    queue<pair<int, int>> q;                    // 대기 큐
    
    // index와 우선순위를 pair로 묶어 대기큐에 push
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
    }
    
    // 대기큐가 빌때까지
    int order =1;
    while(!q.empty()){
        int idx = q.front().first;
        int pri = q.front().second;
        
        bool flag = false;
        for(int i = 0; i < priorities.size(); i++){
            // 다음 인쇄될 문서의 우선순위를 index를 조정하여 원래 priorities 배열에서 찾음
            int next = (idx + 1 + i) % priorities.size();       
            
            // 아직 순서가 지정되지 않았고 우선순위가 더 높은 문서가 존재한다면 큐의 맨 끝에 다시 삽입
            if(orders[next] == 0 && priorities[next] > pri){
                q.push(make_pair(idx, pri));
                q.pop();
                flag = true;
                break;
            }
        }
    
        // 우선순위가 더 높은 문서를 찾지 못했다면 대기큐에서 삭제 = 인쇄하고 순서 저장
        if(!flag){
            q.pop();
            orders[idx] = order;
            order++;
        }
    }
    
    answer = orders[location];
    
    return answer;
}