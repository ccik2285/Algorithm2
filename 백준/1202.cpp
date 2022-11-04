#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> jew(n);
    vector<int> bag(k);
    priority_queue<int,vector<int>, less<int>> pq;
    for(int i=0; i < n; i++) cin >> jew[i].first >> jew[i].second;
    for(int i=0; i < k; i++) cin >> bag[i];
    sort(jew.begin(),jew.end());
    sort(bag.begin(),bag.end());

    int idx = 0;
    long long sum =0;
    for(int i=0; i < k; i++){
        while(idx < n && bag[i] >= jew[idx].first){
            pq.push(jew[idx].second);
            idx++;
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;

}