#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
k번째 수
i번째부터 j번째까지 자른 후 k번째 찾기
*/
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        vector<int> tmp;
        for(int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++){
            tmp.push_back(array[j]);                // i번째부터 j번째까지 push
        }
        sort(tmp.begin(), tmp.end());               // 정렬
        answer.push_back(tmp[commands[i][2] - 1]);  // k번째 수 저장
    }
    
	return answer;
}