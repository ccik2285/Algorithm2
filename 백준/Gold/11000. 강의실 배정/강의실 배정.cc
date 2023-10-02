#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n;
    priority_queue<int,vector<int>,greater<int>> pt;
    cin >> n;
    vector<vector<int>> vt(n,vector<int> (2));
    for(int i=0; i < n; i++){
        int a,b; cin >> a >> b;
        vt[i][0] = a;
        vt[i][1] = b;
    }
    sort(vt.begin(),vt.end());
    
    pt.push(vt[0][1]);

    for(int i=1; i < n; i++){
        if(pt.top() > vt[i][0]){
            pt.push(vt[i][1]);
        }
        else{
            pt.pop();
            pt.push(vt[i][1]);
        }
    }
    cout << pt.size();

}