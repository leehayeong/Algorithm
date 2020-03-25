#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
쇠막대기
레이저에 의해 잘려진 쇠막대기의 총 개수는?

1. 레이저에 잘리면? 스택에 담겨있는 (의 개수만큼 쇠막대기의 개수 증가
2. 쇠막대기가 끝난거면? 쇠막대기 개수 1 증가
*/

int solution(string arrangement) {
    int answer = 0;
    stack<int> s;
    
    for(int i = 0; i < arrangement.length(); i++){
        char cur = arrangement[i];
        
        // 스택에 push
        if(cur == '('){
            s.push(cur);                    
        }
        
        // 괄호 짝이 맞으면 pop
        else if (cur == ')'){
            s.pop();                     
            if(arrangement[i - 1] == '(') answer += s.size();   // 레이저
            else answer++; // 쇠막대기 끝
        }
    }
    
    return answer;
}