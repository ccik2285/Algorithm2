#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--){
        vector<pair<int,int>> vt;
        int ans = 1;
        int n;
        cin >> n;
        for(int i=0; i < n; i++){
            int a,b; 
            cin >> a >> b;
            vt.push_back({a,b});
        }
        sort(vt.begin(),vt.end());
        
        int max_idx = 0;
        for(int i=1; i < n; i++){
            if(vt[max_idx].second > vt[i].second){
                ans++;
                max_idx = i;
                
            }
        }
        cout << ans << endl;
    }

}