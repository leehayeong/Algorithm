#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
큰 수 만들기
abcd... 인 문자열일 때,
a < b 이면 지우고, 지우면 처음부터 탐색
a > b 이면 b부터 탐색
*/

string solution(string number, int k) {
    string answer = number;
    
    int start = 0, next = 1, cnt = 0;
    while(1){    
        if(cnt == k) break;                 // k글자 지우기 완료
        
        if(answer[start] < answer[next]){   // a < b 이면 지우고, idx 처음으로 되돌리기
            answer.erase(start, 1);
            cnt++;
            start = 0;
            next = 1;
        } 
        else {                              // a > b 이면 다음 문자 기준으로 재탐색
            start++;
            next++;
        }
    
        if(next == answer.length()){       // idx가 문자의 끝까지 왔다면, 역순인 상태. 남은 cnt만큼 역으로 다 제거
            int remain = k - cnt;
            answer.erase(next - remain, remain);
            break;
        }
    }
    
    return answer;
}