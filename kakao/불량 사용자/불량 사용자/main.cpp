//
//  main.cpp
//  불량 사용자
//
//  Created by 김수진 on 2021/08/27.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//bool cmp(string a, string b) {
//    return a.length()<b.length();
//}

//int solution(vector<string> user_id, vector<string> banned_id) {
//    vector<string> len[9];
//    int tmp[9]={0,};
//    map<string, int> m;
//    string now_user;
//    string now_banned;
//    int cnt=0;
//    int answer = 0;
//
//    for(int i=0;i<user_id.size();i++) {
//        len[user_id[i].length()].push_back(user_id[i]);
//    }
//    sort(banned_id.begin(), banned_id.end(), cmp);
//    for(int i=0;i<banned_id.size();i++) {
//        now_banned=banned_id[i];
//        int l=now_banned.length();
//        for(int j=0;j<len[l].size();j++) {
//            now_user=len[l][j];
//            for(int k=0;k<l;k++) {
//                if(now_banned[k]=='*') cnt++;
//                else if(now_banned[k]==now_user[k]) cnt++;
//            }
//            if(cnt==l) {
//                tmp[l]++;
//            }
//        }
//    }
//
//    return answer;
//}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<string> v[9];
    map<string, int> m;
    map<string, bool> check;
    int len, cnt=0;
    string now;
    int answer = 0;
    
    for(int i=0;i<user_id.size();i++) {
        len=user_id[i].length();
        v[len].push_back(user_id[i]);
        check[user_id[i]]=false;
    }
    for(int i=0;i<banned_id.size();i++) {
        len=banned_id[i].length();
        m[banned_id[i]]=0;
        for(int j=0;j<v[len].size();j++) {
            now=v[len][j];
            for(int k=0;k<len;k++) {
                if(banned_id[i][k]==now[k]) cnt++;
                else if(banned_id[i][k]=='*') cnt++;
            }
            if(cnt==len) m[banned_id[i]]++;
        }
    }
    for(int)
    
    return answer;
}

int main() {
    
    
    return 0;
}
