#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> vt1,pair<int,int> vt2){
    return vt1.second < vt2.second;
}

int main() {
    int t; cin >> t;
    for(int i=0; i < t; i++){
        vector<pair<int,int>> vt;
        int n; cin >> n;
        int ans = 0;
        int result = 0;
        for(int j=1; j <= n; j++){
            int a; cin >> a;
            result += a;
            vt.push_back(make_pair(j,a));
        }
        sort(vt.begin(),vt.end(),cmp);
        while(result < n*2){
            int k = 0;
            result -= vt[k].second;
            result += max(vt[k].second+vt[k].first,vt[k].first);
            k++;
            ans++;
        }
        cout <<"answer : " << ans << endl;
    }
}