#include <iostream>
#include <iomanip>
using namespace std;
int n;
double p[4]; 
double ans = 1.0000000000000;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void dfs(int curx,int cury,double percent,int cnt,bool visited[30][30]){
    
    if(cnt == n) {       
        return ;
    }
    
    for(int i=0; i < 4; i++){
        if(p[i] == 0) continue;
        int nextx = curx + dx[i];
        int nexty = cury + dy[i];

        if(visited[nextx][nexty] && cnt + 1 <= n){
            ans -= percent * p[i]/100;
            continue;
        }

        visited[nextx][nexty] = true;
        dfs(nextx,nexty,p[i]/100 * percent,cnt + 1,visited);
        visited[nextx][nexty] = false;

    }
}


int main() {
    cin >> n;
    double e,w,n,s; cin >> e >> w >> n >> s;
    bool visited[30][30] = {false,};
    p[0] = e;
    p[1] = w;
    p[2] = n;
    p[3] = s;
    visited[15][15] = true;
    for(int i=0; i < 4; i++){
        if(p[i] == 0) { continue; }
        visited[15+dx[i]][15+dy[i]] = true;
        dfs(15+dx[i],15+dy[i],p[i]/100,1,visited);
        visited[15+dx[i]][15+dy[i]] = false;
    }
    cout << setprecision(14) << ans << endl;
}