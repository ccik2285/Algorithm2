#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int m_max = 0;
bool visited[100001] = {false,};
void dfs(int cur,int sum,vector<int> cost, int x,int cnt){
    if(sum >= x){
        if(sum == x) if(m_max < cnt) m_max = cnt;
        return ;
    }
    if(m_max < cnt) m_max = cnt;
    for(int i=0; i < cost.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i,sum+cost[i],cost,x,cnt + pow(2,i));
            visited[i] = false;
        }
    }

}

int solution(vector<int> cost,int x){
    
    for(int i=0; i < cost.size(); i++){
        visited[i] = true;
        dfs(i,cost[i],cost,x,pow(2,i));
        visited[i] = false;
    }
    return m_max;

}

int main() {
    int n;
    int x;
    cin >> n >> x;
    vector<int> cost(n);
    for(int i=0; i < n; i++){
       cin >> cost[i];
    }
    cout << solution(cost,x);

}