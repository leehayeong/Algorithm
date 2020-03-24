#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
여행경로
ICN에서 시작하여 방문하는 공항 경로를 배열에 담아 return
*/

vector<string> answer, tmp;

bool move(string cur, int cnt, vector<vector<string>> tickets, vector<bool> visited){
    // 모든 티켓 방문 끝나면 종료
    if(cnt == tickets.size()){
        answer = tmp;
        return true;
    }
    
    // 다음 방문지 찾기
    int next;
    for(next = 0; next < tickets.size(); next++){
        // 아직 사용하지 않은 티켓이고, 출발지가 같으면 다음 티켓 사용하여 GO
        if(visited[next] == false && tickets[next][0] == cur) {
            visited[next] = true;
            tmp.push_back(tickets[next][1]);
            if(move(tickets[next][1], cnt + 1, tickets, visited)) return true;  // 모든 티켓 사용 끝나면 완전 종료
            visited[next] = false;
        }
    }
    
    // 다음 방문지를 찾지 못하면, 잘못된 경로이므로 사용 티켓 취소. 다른 경우 탐색해야함을 알림(false)
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 티켓 개수만큼 visited배열 false로 초기화
    vector<bool> visited(tickets.size(), false);
    
    // 역 이름 순 정렬
    sort(tickets.begin(), tickets.end());

    // 시작 공항은 ICN
    tmp.push_back("ICN");
    move("ICN", 0, tickets, visited);

    return answer;
}