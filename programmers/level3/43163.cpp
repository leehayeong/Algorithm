#include <string>
#include <vector>
#include <iostream>

using namespace std;

int wsize, ans = 1000000000;
bool checked[50];

void dfs(int idx, int cnt, string cur, string target, vector<string> words){
    if(cur == target){
        ans = min(ans, cnt);
        return;
    }
    
    for(int i = 0; i < wsize; i++){
        if(checked[i] == false){
            // 한 글자 차이인지 확인
            string ns = words[i];
            int diff = 0;
            for(int j = 0; j < cur.length(); j++){
                if(cur[j] == ns[j]) diff++;
            }
    
            // 한 글자 차이가 아니면 다음으로
            if(diff != cur.length() - 1) continue;
            
            
            // 한 글자 차이이면 다음 조합 구하기
            checked[i] = true;
            dfs(i, cnt + 1, ns, target, words);
            checked[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    wsize = words.size();
    dfs(0, 0, begin, target, words);
    
    if(ans == 1000000000) answer = 0;
    else answer = ans;
        
    return answer;
}