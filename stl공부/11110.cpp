#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    map<int,int> mp;
    set<int> can;
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0; i < lighthouse.size(); i++){
        mp[lighthouse[i][0]]++;
        mp[lighthouse[i][1]]++;
        graph[lighthouse[i][0]][lighthouse[i][1]] = 1;
        graph[lighthouse[i][1]][lighthouse[i][0]] = 1;
        cout << graph[lighthouse[i][0]][lighthouse[i][1]] << endl;
        if(mp[lighthouse[i][0]] > 1) {can.insert(lighthouse[i][0]);}
        else if(mp[lighthouse[i][1]] > 1) {can.insert(lighthouse[i][1]);}
    }
    for(auto tp : can){
        int cnt = 0;
        for(auto tp2 : can){
           // cout << tp << " " << tp2 << endl;
            if(graph[tp][tp2]) cnt++;
        }
    }

    return answer;
}