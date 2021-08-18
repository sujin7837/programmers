//
//  main.cpp
//  파일명 정렬
//
//  Created by 김수진 on 2021/08/04.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct file_sorting {
    string head="";
    string number="";
    int int_number=0;
    string tail="";
    string origin="";
};

bool comp(file_sorting x, file_sorting y) {
    if(x.head==y.head) {
        return x.int_number<y.int_number;
    } else return x.head<y.head;
}

vector<string> solution(vector<string> files) {
    vector<file_sorting> s;
    vector<string> answer;
    file_sorting fs;
    bool visit_head=false;
    int tmp=0;
    
    // head, number, tail 구분
    for(int i=0;i<files.size();i++) {
        for(int j=0;j<files[i].length();j++) {
            if(files[i][j]>='0' && files[i][j]<='9') {
                if(!visit_head) {
                    fs.head=files[i].substr(0,j);
                    tmp=j;
                    visit_head=true;
                }
                if(j+1>=files[i].length()) {
                    fs.number=files[i].substr(j);
                }
                else if(files[i][j+1]>='0' && files[i][j+1]<='9') continue;
                else {
                    fs.number=files[i].substr(tmp,j+1);
                    fs.tail=files[i].substr(j+1);
                    break;
                }
            }
        }
        fs={fs.head,fs.number,0,fs.tail,files[i]};
        s.push_back(fs);
        visit_head=false;
    }
    
    for(int i=0;i<s.size();i++) {
        // head 소문자 변환
        for(int j=0;j<s[i].head.length();j++) {
            s[i].head[j]=tolower(s[i].head[j]);
        }
        
        // number!=0인 경우 불필요한 0 제거
        if(s[i].number.length()!=1) {
            int j=0;
            while(s[i].number[j]=='0') j++;
            s[i].number=s[i].number.substr(j);
        }
        s[i].int_number=stoi(s[i].number);
        
//        if(s[i].tail=="") s[i].tail="a";
    }
    stable_sort(s.begin(),s.end(),comp);
    
    for(int i=0;i<s.size();i++) answer.push_back(s[i].origin);
    
    return answer;
}

int main() {
    vector<string> files={"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat", "foo010bar020.zip", "foo010"};
    
    for(int i=0;i<solution(files).size();i++)
        cout<<solution(files)[i]<<endl;
    
    return 0;
}
