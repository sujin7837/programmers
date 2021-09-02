//
//  main.cpp
//  2056번 작업
//
//  Created by 김수진 on 2021/09/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, time, num, input;
    int maxNum=0;
    int complete[100001];
    vector<int> job[10001];
    
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>time>>num;
        for(int j=0;j<num;j++) {
            cin>>input;
            job[i+1].push_back(input);
        }
        if(num==0) complete[i+1]=time;
        else if(num==1) complete[i+1]=complete[job[i+1][0]]+time;
        else {
            maxNum=complete[job[i+1][0]];
            for(int j=1;j<num;j++) {
                maxNum=max(maxNum,complete[job[i+1][j]]);
            }
            complete[i+1]=maxNum+time;
        }
    }
    maxNum=complete[1];
    for(int i=2;i<=n;i++) {
        maxNum=max(maxNum, complete[i]);
    }
    cout<<maxNum<<endl;
    
    return 0;
}
