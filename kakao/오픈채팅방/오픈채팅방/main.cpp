//
//  main.cpp
//  오픈채팅방
//
//  Created by 김수진 on 2021/08/18.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct User{    // 첫 단어, 유저 아이디, 닉네임을 저장하는 User 구조체를 만든다.
    int num;    // 첫 단어가 Enter: 0, Leave: 1 저장한다.
    string id="";
    string nickname="";
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;    // 유저 아이디를 통해 닉네임을 찾기 위해 map 구조를 사용한다.
    vector<User> uv;    // 입력받은 User 정보를 구조체의 3가지 영역으로 구분하여 저장한다.
    User u;
    string s="", ans="";
    
    // E:0,L:1
    for(int i=0;i<record.size();i++) {
        u.id="";
        u.nickname="";
        s="";
        if(record[i][0]=='E') {    // 첫 단어가 'E'로 시작하는 경우
            u.num=0;
            int j=6;    // 6번째 인덱스부터 유저 아이디가 나온다.
            while(record[i][j]!=' ') {    // 공백이 나오기 전까지를 유저 아이디에 저장한다.
                u.id+=record[i][j];
                j++;
            }
            u.nickname=record[i].substr(j+1);    // 나머지 문자열을 닉네임에 저장한다.
            if(m.count(u.id)==0) m.insert({u.id,u.nickname});    // 유저 아이디 정보가 처음 나온 경우, map에 유저 아이디와 닉네임을 추가한다.
            else m[u.id]=u.nickname;    // 유저 아이디 정보가 이미 있는 경우, 유저 아이디 키값을 새로운 닉네임으로 변경한다.
            u={u.num, u.id, u.nickname};
            uv.push_back(u);
        } else if(record[i][0]=='L') {    // 첫 단어가 'L'로 시작하는 경우
            u.num=1;
            u.id=record[i].substr(6);    // 6번째 인덱스부터 유저 아이디가 나온다.
            u={u.num,u.id,u.nickname};
            uv.push_back(u);
        } else if(record[i][0]=='C') {    // 첫 단어가 'C'로 시작하는 경우
            int j=7;    // 7번째 인덱스부터 유저 아이디가 나온다.
            while(record[i][j]!=' ') {    // 공백이 나오기 전까지를 유저 아이디에 저장한다.
                u.id+=record[i][j];
                j++;
            }
            u.nickname=record[i].substr(j+1);    // 나머지 문자열을 닉네임에 저장한다.
            m[u.id]=u.nickname;    // 유저 아이디 키값을 새로운 닉네임으로 변경한다.
        }
    }
    for(int i=0;i<uv.size();i++) {    // for문을 돌며 uv에 저장된 User 정보를 바탕으로 출력문을 작성한다.
        ans="";
        if(uv[i].num==0) ans=m[uv[i].id]+"님이 들어왔습니다.";
        else if(uv[i].num==1) ans=m[uv[i].id]+"님이 나갔습니다.";
        answer.push_back(ans);
    }
    return answer;
}

int main() {
    
    
    return 0;
}
