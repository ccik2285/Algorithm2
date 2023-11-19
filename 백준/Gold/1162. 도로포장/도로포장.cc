#include <iostream>
#include <vector>
#include <queue>
#define INF 1e15
typedef long long ll;
using namespace std;
int n,m,k;
vector<pair<int,int>> edges[10001];
long long int costs[10001][21] = {0,};
ll ans = INF;
void dj(){
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            costs[i][j] = INF;
        }
    }
    priority_queue<pair<ll, pair<int, int> > > pq;
    pq.push({0, {1, 0}});
    costs[1][0] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second.first;
        int cnt = pq.top().second.second;
        long long int cost = -pq.top().first;
        pq.pop();
        
        if(costs[node][cnt] < cost) continue;
        
        for(int i=0; i<edges[node].size(); i++){
            int next_node = edges[node][i].first;
            ll next_cost = cost + edges[node][i].second;
             
            if(costs[next_node][cnt] > next_cost){ //비사용
                costs[next_node][cnt] = next_cost;
                pq.push({-next_cost, {next_node, cnt}});
            }
             
            if(costs[next_node][cnt+1] > cost && cnt+1 <= k){ //사용
                costs[next_node][cnt+1] = cost;
                pq.push({-cost, {next_node, cnt+1}});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    dj();
    
    for(int i=0; i<=k; i++) ans = min(ans, costs[n][i]);
    cout << ans << endl;
}