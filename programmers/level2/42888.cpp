#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 오픈채팅방

typedef struct {
    string cmd, uid, name;
}Record;

unordered_map<string, string> nicknames;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<Record> list;
    
    int rsize = record.size();
    for(int i = 0; i < rsize; i++){
        string str = record[i];
        
        string cmd, uid, name;
        int cmd_end = str.find(" ");
        int id_end = str.find(" ", cmd_end + 1);
        
        // 상태
        cmd = str.substr(0, cmd_end);

        // 유저아이디 (아이디로 명령이 끝나는 경우 - 떠날 때)
        if(id_end == -1) {             
            uid = str.substr(cmd_end + 1);
        }
        // 유저아이디 + 닉네임
        else {
            uid = str.substr(cmd_end + 1, id_end - cmd_end - 1);   
            name = str.substr(id_end + 1);
        }
        
        // 입장
        if(cmd == "Enter"){
            list.push_back({ cmd, uid, name });
            nicknames[uid] = name;
        }
        // 퇴장
        if(cmd == "Leave") {
            list.push_back({ cmd, uid, nicknames[uid] });
        }
        // 변경
        if(cmd == "Change"){
            nicknames[uid] = name;
        }
    }
    
    int lsize = list.size();
    for(int i = 0; i < lsize; i++){
        string str = nicknames[list[i].uid] + "님이 ";        
        if(list[i].cmd == "Enter") str += "들어왔습니다.";
        else if(list[i].cmd == "Leave") str += "나갔습니다.";
        answer.push_back(str);
    }
    
    return answer;
}