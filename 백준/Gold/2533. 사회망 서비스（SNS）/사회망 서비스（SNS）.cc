#include <iostream>
#include <vector>
using namespace std;
int dp[1000001][2] = {0,};
int n;
vector<vector<int>> edges;
bool visited[1000001] = {false,};
//0은 얼리 x
//1은 얼리 o
void dfs(int node){
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;
    
    for(int i=0; i<edges[node].size(); i++){
        int next = edges[node][i]; 
        
        if(visited[next]) continue;  
        
        dfs(next);
        
        dp[node][0] += dp[next][1];
        dp[node][1] += min(dp[next][0], dp[next][1]); 
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    edges.resize(n+1);
    for(int i=0; i < n-1; i++){
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}


