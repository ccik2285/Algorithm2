#include <string>
#include <vector>

using namespace std;
int dp[100001][2];
bool visited[100001] = {false,};
vector<int> ed[100001];
void dfs(int idx){
    dp[idx][0] = 0; //n번째가 켜졌을때
    dp[idx][1] = 1; //n번째가 꺼졌을때
    visited[idx] = true;
    for(int i=0; i < ed[idx].size(); i++){
        int next = ed[idx][i];
        if(visited[next]) continue;
        dfs(next);
        dp[idx][1] += min(dp[next][1],dp[next][0]);
        dp[idx][0] += dp[next][1];
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    
    for(int i=0; i < lighthouse.size(); i++){
        int start = lighthouse[i][0]; int end = lighthouse[i][1];
        ed[start].push_back(end);
        ed[end].push_back(start);
    }
    
    dfs(1);
    answer = min(dp[1][0],dp[1][1]);
    return answer;
}