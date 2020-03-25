#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
다리를 지나는 트럭
트럭들이 다리를 모두 완전히 지나는 데 걸리는 시간은?
*/

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;   // 걸리는 시간
	queue<int> queue; // 다리에 들어와있는 트럭 리스트
	vector<int> sec;  // 트럭별로 걸린 시간

    // 트럭이 모두 건널때까지
	int i = 0; int sum = 0;
    while (i < truck_weights.size()) {
        // 건너갈 수 있으면
		if (sum + truck_weights[i] <= weight) {
			queue.push(truck_weights[i]);           // 다리 큐에 트럭 push
			sec.push_back(bridge_length);           // 건너가기 위한 다리 길이 push
			sum += truck_weights[i];                // 다리 위의 트럭 무게 합 갱신
			i++;                                    // 다음 트럭도 건너갈 수 있는지 확인
		}

        // 다리 위에 있는 트럭들 지나간 길이 갱신 (1씩 감소)
		for (int j = 0; j < sec.size(); j++) {
			sec[j]--;
		}

        // 다리를 모두 지나간 트럭 찾기
		for (int j = 0; j < sec.size(); j++) {
			if (sec[j] == 0) {
                sum -= queue.front();               // 지나간 트럭 다리 위 무게 합에서 빼고
				queue.pop();                        // 큐에서 삭제
				sec[j] = -1;                        // 지나갔으므로 길이 -1로 고정
			}
		}
        
        answer++;   // 1초 증가
	}
    
    // 다리 위에서 가장 마지막에 있는 트럭 찾아 완전히 지나가는 데 걸리는 시간 계산
    int last = sec[sec.size()-1];
    answer += (last + 1);
    
	return answer;
}


/*
// 더 오래 걸린 풀이
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> wait;
    queue<pair<int, int>> bridge;
    vector<int> time (truck_weights.size(), -1);
    
    // 큐에 트럭 삽입
    for(int i = 0; i < truck_weights.size(); i++){
        wait.push(make_pair(i, truck_weights[i]));
    }
    
    // 모든 트럭이 빠져나갈때까지 반복
    int weight_sum = 0;
    while(1){
        answer++;  // 1초 증가
                
        int cur_idx = wait.front().first;
        int cur_weight = wait.front().second;
        
        // 트럭 진입할 수 있으면
        if(weight_sum + cur_weight <= weight){              
            weight_sum += cur_weight;                       // 무게 더하고
            bridge.push(make_pair(cur_idx, cur_weight));    // 다리 위에 있는 트럭으로 옮기고
            wait.pop();                                     // 대기트럭에서 제거
            time[cur_idx]++;                                // 트럭이 지나간 길이 갱신
        } 
        
        // 다리 위에 있는 트럭들 한 칸씩 이동하며 지나간 길이 갱신
        for(int i = 0; i < truck_weights.size(); i++){
            if(time[i] != -1) {
                time[i]++;
                
                // 다 건너면 빠져나옴
                if(time[i] == bridge_length){
                    weight_sum -= bridge.front().second;
                    bridge.pop();
                    time[i] = -1;
                }
            }
        }
        
        // 대기하는 트럭과 다리위에 있는 트럭이 모두 없다면 끝
        if(wait.empty() && bridge.empty()) break;

        // 다리위에만 트럭이 있다면
        if(wait.empty() && !bridge.empty()){
            // 가장 마지막 트럭 찾고
            int last;
            while(!bridge.empty()){
                last = bridge.front().first;
                bridge.pop();
            }
            // 마지막 트럭이 통과할때까지 걸리는 시간 더해준 뒤 종료
            answer += (bridge_length - time[last]);
            break;
        }
    }
    
    return answer + 1;
}
*/