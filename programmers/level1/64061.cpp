#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/*
크레인 인형뽑기 게임
크레인을 작동시킨 위치에 따라 이동시켰을 때, 터트려진 인형의 개수는?
*/

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    stack<int> bucket;
    
    for(int i = 0; i < moves.size(); i++){
        int cur = moves[i] - 1;
        int depth = 0;
        while(depth < size && board[depth][cur] == 0) depth++; // 인형 찾기
        if(depth >= size) continue;                            // 인형 없음
        
        // 인형 바구니에 넣고, 인형 뽑았으므로 0으로 변경
        bucket.push(board[depth][cur]);
        board[depth][cur] = 0;              
        
        // 터질 수 있는지 확인
        if(bucket.size() >= 2){
            int first = bucket.top(); bucket.pop();
            int second = bucket.top(); bucket.pop();
            if(first == second) {
                answer += 2;
            }
            else {
                bucket.push(second);
                bucket.push(first);
            }
        }
    }
    
    return answer;
}