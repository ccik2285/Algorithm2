#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> q;
    vector<int> visited(n+1,false);
    vector<int> distance(n+1,0);
    vector<vector<int>> graph(n+1);
    
    for(int i=0; i < edge.size(); i++)
    {
        int start = edge[i][0]; 
        int end = edge[i][1];
        
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int start = q.front();
        
        q.pop();
        
        for(int i=0; i < graph[start].size(); i++)
        {
            int end = graph[start][i];
            if(!visited[end]){
                q.push(end);
                distance[end] = distance[start] + 1;
                visited[end] = true;
            }
        }
        
    }
    sort(distance.begin(),distance.end(),cmp);
    for(auto a : distance){
        if(a == distance[0]){
            answer++;
        }
    }
    
    return answer;
}