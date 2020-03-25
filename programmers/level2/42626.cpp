#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
더 맵게
스코빌 지수를 K이상으로 만들기 위해 섞어야하는 최소 횟수는?
스코빌지수 = 가장 맵지 않은 음식 + (두번째로 맵지 않은 음식 * 2)
*/

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;  // 큐에 담긴 수가 작은 순 -> 큰 순으로 되도록
    
    // 작은수가 앞에 오도록 우선순위큐에 push
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    // 마지막 스코빌 지수를 만들 수 있을 때까지
    while(pq.size() >= 2){
        if(pq.top() >= K) break;        // 가장 작은 수인 가장 앞 수가 K보다 크면, 모든 수가 K보다 큼
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int cal = first + second * 2;
        pq.push(cal);
        answer++;
    }
   
    if(pq.top() < K) answer = -1;       // 모든 수를 섞었는데도 가장 작은 수가 K보다 작다면 만들 수 없는 것
    
    return answer;
}