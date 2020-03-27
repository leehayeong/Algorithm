#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
AAA 에서 주어진 문자를 만드는 최소 횟수는?
위, 아래 이동은 N과 M을 기준으로 A와 Z중 어느쪽에 가깝게 있는지에 따라 이동 방향이 달라짐
*/

int solution(string name) {
    int answer = 0;
    int name_length = name.length();            // 만들어야 할 알파벳 개수
    vector<bool> finish(name_length, false);    // 각 자리별로 만들었는지?    
    string init(name.length(), 'A');
    
    int i = 0;
    while(1){
        // 알파벳 만들기 (위, 아래 이동 중 더 효율적인 곳 찾기)
        char c = name[i];
        if(c != 'A') {
            if('B' <= c && c <= 'M') answer += c - 'A';
            else if ('N' <= c && c <= 'Z') answer += 'Z' - c + 1;
            init[i] = c;
        }
        finish[i] = true;

        // name으로 모두 만들었으면 종료
        if(init == name) break;
        
        // 커서를 오른쪽, 왼쪽으로 이동할 때 이동 횟수 각각 구하기
        int right = (i + 1) % name_length; 
        int right_cnt = 1;
        while(!(name[right] != 'A' && finish[right] == false)) {
            right = (right + 1) % name_length;
            right_cnt++;
        }
        int left = (i + name_length - 1) % name_length;
        int left_cnt = 1;
        while(!(name[left] != 'A' && finish[left] == false)) {
            left = (left + name_length - 1) % name_length;
            left_cnt++;
        }

        // 더 적게 이동하는 방향을 선택
        if(right_cnt <= left_cnt){
            i = right;
            answer += right_cnt; 
        } else {
            i = left;
            answer += left_cnt;
        }
    }
    
    return answer;
}