//
//  main.cpp
//  길 찾기 게임
//
//  Created by 김수진 on 2021/08/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;

struct Node {
    int root;
    int left=-1;
    int right=-1;
};

vector<Node> node;
map<pair<int, int>,int> m;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first==b.first) return a.second<b.second;
    else return a.first>b.first;
}

void makeTree(vector<pair<int, int>> x) {
    Node n;
    int nx, ny;
    int ry=x[0].second;
    int rx=x[0].first;
    for(int i=1;i<x.size();i++) {
        n.root=m[{x[i-1].first, x[i-1].second}];
        nx=x[i].first;
        ny=x[i].second;
        if(rx<nx) {
            n.left=m[{x[i].first, x[i].second}];
        } else n.right=m[{x[i].first, x[i].second}];
        
        rx=nx;
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int,int>> v;
    deque<int> dq;
    bool visit[10001]={false,};
    
    int len=nodeinfo.size();
    int now;
    
    for(int i=0;i<len;i++) {
        m.insert({{nodeinfo[i][0],nodeinfo[i][1]}, i});
        v.push_back({nodeinfo[i][0], nodeinfo[i][1]});
    }
    sort(v.begin(), v.end(), cmp);
    
    int startx=v[0].first;
    int starty=v[0].second;
    dq.push_back(m[{startx,starty}]);
    for(int i=1;i<len;i++) {
        int nx=v[i].first;
        int ny=v[i].second;
        
        if(
    }
    
    
    return answer;
}

int main() {
    
    return 0;
}
