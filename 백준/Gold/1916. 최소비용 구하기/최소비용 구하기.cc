#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<pair<int,int>> arr[1001]; 
int dist[1001];
void dj(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({start,0});

    while(!pq.empty()){
        int cur = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if(d > dist[cur]) continue;

        for(int i=0; i < arr[cur].size(); i++){
            int next = arr[cur][i].first;
            int nextdis = d + arr[cur][i].second;

            if(nextdis < dist[next]){
                dist[next] = nextdis;
                pq.push({next,nextdis});
            }
        }

    }

}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        arr[a].push_back({b,c});
    }
    int start,end; cin >> start >> end;

    for(int i=0; i < 1001; i++) dist[i] = 987654321;
    dj(start);
    printf("%d",dist[end]);

}