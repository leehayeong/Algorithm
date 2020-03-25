#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
기능개발
뒤 기능이 앞 기능보다 먼저 개발될 수 있지만, 배포는 앞 기능이 배포된다.
각 배포마다 몇개의 기능이 배포되는지?
*/

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    // 순서대로 처리되어야 할 작업 index로 큐에 삽입
    for(int i = 0; i < progresses.size(); i++){
        q.push(i);
    }
       
    // 큐에 있는 모든 작업이 완료될 때까지
    while(!q.empty()){
        // 작업량 갱신
        for(int i = 0; i < progresses.size(); i++){
            progresses[i] += speeds[i];
        }
        
        // 배포할 수 있는지 확인
        int cnt = 0;
        for(int  i = 0; i < progresses.size(); i++){
            // 큐의 가장 앞에 있는 작업이 100이상이면 큐에서 제거
            if(i == q.front() && progresses[i] >= 100){
                q.pop();
                cnt++;      // 배포 개수 증가
            }
        }
        
        // 배포할 작업이 있으면 배포 개수 저장
        if(cnt != 0) answer.push_back(cnt);
    }    
               
    return answer;
}