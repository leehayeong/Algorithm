#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
주식가격
가격이 떨어지지 않은 기간은 몇 초?
*/

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices);
    queue<pair<int, int>> q;
    
    for(int i = 0; i < prices.size(); i++){
        q.push(make_pair(i, prices[i]));
    }
    
    while(!q.empty()){
        int idx = q.front().first;
        int num = q.front().second;
        int cnt = 0;
        q.pop();
        
        // 현재보다 떨어지는 지점 찾기
        for(int i = idx + 1; i < prices.size(); i++){
            cnt++;                      // 1초 지남
            if(prices[i] < num) break;  // 현재 금액보다 작아질 때 break
        }
        
        answer[idx] = cnt;
    }
    
    
    return answer;
}

/*
// 큐 미사용. 2차원 포문 사용 풀이
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int sec = 0;
    
    for(int i = 0; i < prices.size(); i++){
        for(int j = i+1; j < prices.size(); j++){
            sec++;
            if(prices[i] > prices[j]) break;
        }
        answer.push_back(sec);
        sec = 0;
    }
    
    return answer;
}
*/