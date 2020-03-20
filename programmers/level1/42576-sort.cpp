#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 이름 순 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    // 이름이 같지 않을 때가 완주하지 못한 선수가 나올 때
    for(int i = 0; i < participant.size(); i++){
        // 참가자의 마지막 순서까지 반복문이 왔다면, 마지막 참가자가 완주하지 못한 선수임
        if(i == participant.size() - 1){
            answer = participant[i];
            break;
        }
        
        if(participant[i] != completion[i]){
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}