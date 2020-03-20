#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m;
    
    // 참가자 ++, 완주자 -- 
    for(int i = 0; i < participant.size(); i++){
        m[participant[i]]++;
    }
    for(int i = 0; i < completion.size(); i++){
        m[completion[i]]--;
    }

    // 결과 확인 => 참가하고 완주한 사람은 결과 = 0, 그렇지 않은 사람은 != 0
    for(int i = 0; i < participant.size(); i++){
        if(m[participant[i]] != 0){
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}