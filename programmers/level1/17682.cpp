#include <string>
#include <iostream>
#include <cmath>

using namespace std;

/*
다트 게임
정수와 문자열이 입력될 때 총 점수는?
*/

int solution(string dartResult) {
    int answer = 0;
    int length = dartResult.length();
    
    int score[3];   // 점수 저장
    int nidx = 0;   // 저장할 점수 idx
    int cnt = 0;    // 자릿수 (2면 무조건 10점)
    for(int i = 0; i < length; i++){
        if ('0' <= dartResult[i] && dartResult[i] <= '9'){
            cnt++;
            continue;
        }
        
        // 점수 저장
        if (cnt == 1){
            score[nidx] = dartResult[i - 1] - '0';
            cnt = 0;
            nidx++;
        } 
        else if (cnt == 2){
            score[nidx] = 10;
            cnt = 0;
            nidx++;
        }

        // 보너스, 옵션 적용
        int curIdx = nidx - 1;
        if (dartResult[i] == 'S'){
            score[curIdx] = score[curIdx];
        }
        else if (dartResult[i] == 'D'){
            score[curIdx] = pow(score[curIdx], 2);
        }
        else if (dartResult[i] == 'T'){
            score[curIdx] = pow(score[curIdx], 3);
        }
        else if (dartResult[i] == '*'){
            score[curIdx] *= 2;
            if (curIdx != 0) score[curIdx - 1] *= 2;
        }
        else if (dartResult[i] == '#'){
            score[curIdx] *= -1;
        }
    }
    
    // 합 계산
    for(int i = 0; i < 3; i++){
        answer += score[i];
    }
    
    return answer;
}

/*
조건
기회마다 얻을 수 있는 점수는 0-10점
S=1제곱, D=2제곱, T=3제곱
*=해당점수와 직전점수 2배
#=해당점수 마이너스

예외처리
1. *가 첫번째에 나오면, 해당점수만 2배 (직전점수 없으므로)
2. *효과는 다른 *효과와 중첩 가능 (중첩된 점수는 4배)
3. *효과는 # 효과와 중첩 가능 (중첩된 점수는 -2배)
4. S, D, T는 점수마다 하나씩 존재
5. *, #은 점수마다 둘 중 하나만 존재 / 존재하지 않을 수도
*/