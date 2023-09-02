#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> vt;
    vector<int> gap(n-1);
    int ans = 0;
    for(int i=0; i < n; i++){
        int a; cin >> a;
        vt.push_back(a);
    }

    for(int i=1; i < n; i++){
        gap[i-1] = vt[i] - vt[i-1];
    }

    sort(gap.begin(),gap.end());

    for(int i=0; i < n-m; i++){
        ans += gap[i];
    }

    cout << ans << endl;
    
    
}