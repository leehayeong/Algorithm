#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>> pq1;                   // 내림차순
    priority_queue<int, vector<int>, greater<int>> pq2;     // 오름차순
    int qsize = 0;                                          // 큐 사이즈
    
    // 연산
    for(int i = 0; i < operations.size(); i++){
        if(operations[i][0] == 'I'){        // 삽입
            int num = atoi(operations[i].substr(2).c_str());
            pq1.push(num);
            pq2.push(num);
            qsize++;
        }
        else if(operations[i] == "D 1"){    // 최댓값 삭제
            if(qsize == 0) continue;
            pq1.pop();
            qsize--;
        }
        else if (operations[i] == "D -1"){  // 최솟값 삭제
            if(qsize == 0) continue;
            pq2.pop();
            qsize--;
        }
        
        if(qsize == 0) {    // 큐가 비면 두 큐 모두 초기화
            priority_queue<int, vector<int>> empty1;
            priority_queue<int, vector<int>, greater<int>> empty2;
            swap(pq1, empty1);
            swap(pq2, empty2);
        }
    }
    
    // 최댓값, 최솟값 구하기
    if(qsize == 0){
        answer.push_back(0);
        answer.push_back(0);
    } 
    else {
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }
  
    return answer;
}