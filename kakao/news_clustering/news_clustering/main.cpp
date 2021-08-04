//
//  main.cpp
//  news_clustering
//
//  Created by 김수진 on 2021/07/19.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    string str1 = "FRA-NCE+";
    string str2 = "fre--nch";

    vector<string> new_str1(1001);
    vector<string> new_str2(1001);
    vector<string> con;
    vector<string> sum;
    
    int conNum=0;
    int sumNum=0;
    int answer=0;

    for(int i=0;i<str1.length()-1;i++) {
        new_str1[i].push_back(str1[i]);
        new_str1[i].push_back(str1[i+1]);
    }
    
    for(int i=0;i<str2.length()-1;i++) {
        new_str2[i].push_back(str2[i]);
        new_str2[i].push_back(str2[i+1]);
    }

    for(int i=0;i<str1.length();i++) {
        for(int j=0;j<2;j++) {
            if(new_str1[i][j]>='A' && new_str1[i][j]<='Z') {
                new_str1[i][j]=new_str1[i][j]-'A'+'a';
            }
        }
    }
    
    for(int i=0;i<str1.length();) { //0:e- 1:-- 2:-n
        if(!(new_str1[i][0]>='a' && new_str1[i][0]<='z') || !(new_str1[i][1]>='a' && new_str1[i][1]<='z')) {
            new_str1.erase(new_str1.begin()+i);
        }
        else i++;
    }
    for(int i=0;i<str1.length();i++) cout<<new_str1[i]<<endl;
    
    for(int i=0;i<str2.length();i++) {
        for(int j=0;j<2;j++) {
            if(new_str2[i][j]>='A' && new_str2[i][j]<='Z') {
                new_str2[i][j]=new_str2[i][j]-'A'+'a';
            }
            if(!(new_str2[i][j]>='a' && new_str2[i][j]<='z')) {
                new_str2.erase(new_str2.begin()+i);
            }
        }
        cout<<new_str2[i]<<endl;
    }
//
//    for(int i=0;i<new_str1.size();) {
//        for(int j=0;j<new_str2.size();) {
//            if(new_str1[i]==new_str2[j]) {
//                con.push_back(new_str1[i]);
//                new_str1.erase(new_str1.begin()+i);
//                new_str2.erase(new_str2.begin()+j);
//            }
//            i++; j++;
//        }
//    }
//    conNum=con.size();
//    sumNum=conNum+new_str1.size()+new_str2.size();
//    answer=conNum/sumNum;
//
//    cout<<conNum<<endl<<sumNum<<endl;

    return 0;
}
