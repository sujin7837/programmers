//
//  main.cpp
//  튜플
//
//  Created by 김수진 on 2021/08/27.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
    return a.length()<b.length();
}

vector<int> solution(string s) {
    int num, start=1;
    int len=s.length();
    string tmp;
    vector<string> vs;
    vector<int> answer;
    
    for(int i=1;i<len-1;i++) {
        if(s[i]=='}') {
            tmp=s.substr(start, i-start+1);
            vs.push_back(tmp);
            start=i+2;
        }
    }
    sort(vs.begin(), vs.end(), cmp);
    for(int i=0;i<vs.size();i++) {
        tmp="";
        for(int j=0;j<vs[i].size();j++) {
            if(isdigit(vs[i][j])) tmp+=vs[i][j];
            else {
                if(tmp!="") {
                    num=stoi(tmp);
                if(answer.empty()) answer.push_back(num);
                else {
                    auto it=find(answer.begin(), answer.end(), num);
                    if(it==answer.end()) answer.push_back(num);
                }
                }
                tmp="";
            }
        }
    }
    
    return answer;
}

int main() {
    string s="{{20,111},{111}}";
    for(int i=0;i<solution(s).size();i++)
        cout<<solution(s)[i]<<endl;
    
    return 0;
}
