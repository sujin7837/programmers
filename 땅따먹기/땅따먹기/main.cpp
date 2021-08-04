//
//  main.cpp
//  땅따먹기
//
//  Created by 김수진 on 2021/04/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(9);
    v.push_back(7);
    
    do {
        for(int i=0;i<v.size();i++) {
            cout<<v[i];
        }
        cout<<endl;
        
    }while(next_permutation(v.begin(), v.end()));
    
    
    return 0;
}
