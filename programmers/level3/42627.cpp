#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

/*
디스크 컨트롤러
평균 작업 시간의 최소는?

1. 작업이 도착했을 때 pq에 push (소요시간별로 작은순으로 되도록)
2. 작업이 끝났을 때 pq에서 pop (가장 짧은 시간이 걸리는 작업이 먼저 수행되도록)
*/

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;		// 수행시간, index
    vector<pair<int, int>> result(jobs.size(), make_pair(0, 0));				// 대기시간, 수행시간 저장
        
    // 요청된 순서대로 정렬
    sort(jobs.begin(), jobs.end());         

    // 스케쥴러 시작
    int i = 0;		// 현재 시간
    int j = 0;		// jobs 탐색 idx
    int finish = 0;		// 다음 작업이 끝날 시간
    int cnt = 0;		// 완료된 작업 수
    bool processing = false;	// 수행중인지 여부
    
    while(cnt < jobs.size()){			// 모든 작업이 수행될때까지    
        if(i >= finish) processing = false;	// 수행중인 작업의 종료시간이 되면 작업하고 있는 것이 없음을 알림
     
        while(j < jobs.size() && i == jobs[j][0]){	// 현재 도착한 작업이 있다면 모두 push
            pq.push(make_pair(jobs[j][1], j));
            j++;
        }

        if(!processing && !pq.empty()){		// 현재 수행하고 있는 작업이 없으면 pop 하여 작업 수행
            int idx = pq.top().second;		// 인덱스
            pq.pop();
            result[idx].first = i - jobs[idx][0];	// 대기시간 = 현재시간 - 도착시간
            result[idx].second = jobs[idx][1];	// 수행시간
            finish = i + jobs[idx][1];		// 종료시간 = 현재시간 + 수행시간
            processing = true;
            cnt++;

            if(pq.empty() && j < jobs.size()) {	// 작업이 끝난 뒤 큐가 비었다면, 다음 작업이 올 때로 시간 jump
                i = jobs[j][0];
                continue;
            } 
        }
        
        i++;				// 시간 흐름
    }
    
    // 평균 시간 계산 (총수행시간 = 대기시간+수행시간)
    for(int i = 0; i < result.size(); i++){
        answer += result[i].first + result[i]. second;
    }
    answer = answer / result.size();
    
    return answer;
}