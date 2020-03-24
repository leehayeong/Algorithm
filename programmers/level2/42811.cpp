#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
숫자 야구
숫자O, 위치X 볼, 숫자O, 위치O 스트라이크, 숫자X, 위치X 아웃
가능한 답은?
*/

int solution(vector<vector<int>> baseball) {    
    int answer = 0;
    
    // 가능 한 수 전체 탐색
    for(int i = 123; i <= 987; i++){
        int one = i / 100;
        int two = (i / 10) % 10;
        int three = (i % 100) % 10;
    
        // 숫자가 중복해서 나오거나 0이 나오면 불가능한 수이므로 continue
        if(one == two || one == three || two == three || one == 0 || two == 0 || three == 0) continue;
        
        // 질문과 비교
        bool flag = true;
        for(int i = 0; i < baseball.size(); i++){
            int num = baseball[i][0];       // 질문 세자리수
            int n_one = num / 100;
            int n_two = (num / 10) % 10;
            int n_three = (num % 100) % 10;
            int strike = 0, ball = 0;

            // 스트라이크 수 세기
            // 현재 수의 자릿수 값과, 질문 수의 같은 자릿수 값이 일치할 때에만 스트라이크 수 ++ (수,위치 모두 일치)
            if(one == n_one) strike++;
            if(two == n_two) strike++;
            if(three == n_three) strike++;
            
            // 볼 수 세기
            // 현재 수의 자릿수 값이, 질문 수의 다른 자릿수의 값과 일치할 때에만 볼 수 ++ (수일치, 위치불일치)
            if(one == n_two || one == n_three) ball++;
            if(two == n_one || two == n_three) ball++;
            if(three == n_one || three == n_two) ball++;

            // 구한 스트라이크 수와 볼 수가 질문에서 말한 스트라이크 수와 볼 수와 같지않으면 불가능한 수
            if(strike != baseball[i][1] || ball != baseball[i][2]) {
                flag = false;
                break;
            }
        }
        
        // 질문 모두 통과하여 flag = true라면 가능한 수이므로 답 ++
        if(flag) answer++;
    }    
    
    return answer;
}