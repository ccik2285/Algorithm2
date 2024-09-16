#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;
int n,m; 
bool visited[101][101] = {false,}; 
char arr[101][101] = {};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0}; 
int team_b = 0;
int team_w = 0;
map<char,int> mp;
int cnt = 0;

void dfs(int x, int y, char cur_team) {

    for(int i=0; i < 4; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if((nextx >= 0 && nextx < n) && (nexty >= 0 && nexty < m)){
            if(!visited[nextx][nexty] && cur_team == arr[nextx][nexty]){
                visited[nextx][nexty] = true;
                cnt++; 
                dfs(nextx, nexty, cur_team);
            }
        }
    }

}

int main() {
    cin >> m >> n;

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(!visited[i][j] && (arr[i][j] == 'B' || arr[i][j] == 'W')){
                cnt = 1;
                visited[i][j] = true;
                dfs(i,j,arr[i][j]);
                mp[arr[i][j]] += pow(cnt,2);
            }
        }
    }

    cout << mp['W'] << " " << mp['B'] << endl;


}