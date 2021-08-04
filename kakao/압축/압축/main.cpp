//
//  main.cpp
//  압축
//
//  Created by 김수진 on 2021/08/04.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> vs;
    string s="";
    string w,c;

    // A~Z를 사전에 미리 추가한다.
    for(int i=0;i<26;i++) {
        s+=char('A'+i);
        vs.push_back(s);
        s="";
    }
    
    if(msg.length()==1) {
        answer.push_back(int(msg[0]-'A'+1));
    } else {
        w=msg[0]; c=msg[1];
        int i=1;
        while(i<msg.length()) {
            auto it=find(vs.begin(),vs.end(),w+c);
            if(it!=vs.end()) {  // 글자가 사전에 존재할 때
                w=w+c;
                i++;
                if(i<msg.length())
                    c=msg[i];
                else {
                    c="";
                    break;
                }
            } else {    // 글자가 사전에 존재하지 않을 때
                auto it3=find(vs.begin(),vs.end(),w);
                answer.push_back((it3-vs.begin())+1);
                vs.push_back(w+c);
                w=c;
                i++;
                if(i<msg.length())
                    c=msg[i];
                else {
                    c="";
                    break;
                }
            }
        }
        if(w!="" && c=="") {
            auto it=find(vs.begin(),vs.end(),w);
            if(it!=vs.end()) answer.push_back((it-vs.begin())+1);
            else answer.push_back(vs.size());
        }
    }
    return answer;
}

int main() {
    vector<int> ss=solution("K");
    for(int i=0;i<ss.size();i++)
        cout<<ss[i]<<endl;

    return 0;
}
