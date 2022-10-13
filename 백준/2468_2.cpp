#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[101][101] = {false,};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x,int y, int np,vector<vector<int>> maps){
    
    for(int i=0; i<4; i++){
        int x_ = dx[i] + x;
        int y_ = dy[i] + y;

        if(x_ < 0 || x_ >= maps.size() || y_ < 0 || y_ >= maps.size()) continue;
        if(maps[x_][y_] > np && !visited[x_][y_]){
            visited[x_][y_] = true;
            dfs(x_,y_,np,maps);
        }
    }

}


int solution(vector<vector<int>> maps){
    int answer = 0;
    int max = 0;
    vector<int> ans;
    for(int i=0; i < maps.size(); i++){
        for(int j=0; j < maps.size(); j++){
            if(max < maps[i][j]) max = maps[i][j];
        }
    } 
    

    int np = 1;
    while(np <= max){
        int cnt = 0;

        for(int i=0; i< maps.size(); i++){
            for(int j=0; j<maps.size(); j++) visited[i][j] = false;
        }

        for(int i=0; i < maps.size(); i++){
            for(int j=0; j < maps.size(); j++){
                if(!visited[i][j] && maps[i][j] > np){
                    visited[i][j] = true;
                    cnt++;
                    dfs(i,j,np,maps);
                }
            }
        }
        ans.push_back(cnt); 
        np++;
    }
    answer = *max_element(ans.begin(),ans.end());
    return answer;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; 
    cin >> n;
    vector<vector<int>> maps(n,vector<int>(n));
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            int a; cin >> a;
            maps[i][j] = a;
        }
    }
    cout << solution(maps);
    
}