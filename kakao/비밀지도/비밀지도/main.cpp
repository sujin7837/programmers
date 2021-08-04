//
//  main.cpp
//  비밀지도
//
//  Created by 김수진 on 2021/07/19.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string tenToTwo(int x) {
    string s;
    while(x!=0) {
        s=(x%2==0?"0":"1")+s;
        x/=2;
    }
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string arr1_s[n+1];
    string arr2_s[n+1];
    string ss;
    int len1[n+1];
    int len2[n+2];
    
    for(int i=0;i<n;i++) {
        arr1_s[i]=tenToTwo(arr1[i]);
        arr2_s[i]=tenToTwo(arr2[i]);
        len1[i]=arr1_s[i].length();
        len2[i]=arr2_s[i].length();
        
        for(int j=0;j<n-len1[i];j++) {
            arr1_s[i]="0"+arr1_s[i];
            
        }
        for(int j=0;j<n-len2[i];j++) {
            arr2_s[i]="0"+arr2_s[i];
            
        }
                
        for(int j=0;j<n;j++) {
            if(arr1_s[i][j]=='0' && arr2_s[i][j]=='0') ss+=" ";
            else ss+="#";
        }
        answer.push_back(ss);
        ss="";
    }
    
    return answer;
}

int main() {
    vector<int> arr1={46, 33, 33 ,22, 31, 50};
    vector<int> arr2={27 ,56, 19, 14, 14, 10};
    for(int i=0;i<6;i++)
    cout<<solution(6, arr1, arr2)[i]<<endl;
//    solution(5, arr1, arr2);
    
    return 0;
}
