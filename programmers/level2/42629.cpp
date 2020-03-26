#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

/*
라면공장
최소 몇 번 해외 공장으로무터 밀가루를 공급받아야하는지?
밀가루를 공급받는 시점에 밀가루를 pq에 넣고, 떨어진 시점에 pop한다.
*/

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int, vector<int>> pq;
    
    // k일에는 원래 공장에서 공급받기 때문에 k-1일까지만 해외에서 공급
    for(int i = 1, j = 0; i < k; i++){
        stock--;
        
        // 공급이 있는 날이면 pq에 push
        if(j < dates.size() && i == dates[j]){
            pq.push(supplies[j]);
            j++;
        }
        
        // 밀가루가 다 떨어지면 pq에서 밀가루 공급받음
        if(stock == 0){
            stock += pq.top();
            pq.pop();
            answer++;
        }
    }
    
    return answer;
}