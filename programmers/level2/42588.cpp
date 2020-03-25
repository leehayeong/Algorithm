#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/*
탑
탐이 쏜 신호를 어느 탑에서 받았는지 알아내라.
*/

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;
    stack<int> result;
    
    // 송신탑의 높이 스택에 모두 push
    for(int i = 0; i < heights.size(); i++){
        s.push(heights[i]);  
    }
    
    // 스택에서 송신 탑의 수만큼 모두 꺼내 탐색
    for(int i = heights.size() - 1; i >= 0; i--){
        int height = s.top();
        s.pop();
        
        bool flag = false;
        for(int j = i - 1; j >= 0; j--){    // 왼쪽으로 가면서 탐색
            if(height < heights[j]){        // 신호를 받을 수 있으면 받은 탑의 번호 결과 스택에 push
                result.push(j + 1);
                flag = true;
                break;
            }
        }
        
        if(!flag) result.push(0);           // 못받으면 0 push
    }
    
    // 결과 스택에서 꺼내 answer에 저장
    while(!result.empty()){
        answer.push_back(result.top());
        result.pop();
    }
    
    return answer;
}

/*
// 배열 사용 풀이. 거꾸로 읽으면서 왼쪽으로 가면서 자신보다 수가 크면 기록
vector<int> solution(vector<int> heights) {
    vector<int> answer;

    for(int i = heights.size()-1; i >= 1; i--){
        for(int j = i-1; j >=0; j--){
            if(heights[i] < heights[j]){
                answer.push_back(j+1);
                break;
            }
        }
    }
    
    return answer;
}
*/