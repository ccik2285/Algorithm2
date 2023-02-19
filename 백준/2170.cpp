// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(0);
//      cout.tie(0);
//     vector<pair<int,int>> dot;
//     int n;
//     cin >> n;
//     for(int i=0; i<n; i++){
//         int a,b;
//         cin >> a >> b;
//         dot.push_back({a,b});
//     }
//     sort(dot.begin(),dot.end());
//     int from = dot[0].first;
//     int to = dot[0].second;
//     int ans = 0;
//     for(int i=1; i < dot.size(); i++){
//         if(to >= dot[i].first) {
//             to = max(to,dot[i].second);
//         }
//         else {
//             ans += to - from;
//             from = dot[i].first;
//             to = dot[i].second;
//         }
        
//     }
//     ans += to-from;
//     cout << ans;

// }
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<pair<int, int> > arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(), arr.end());
    int ans=0;
    int start = arr[0].first, end = arr[0].second;
    for(int i=1 ; i<n ; i++) {
        int s = arr[i].first, e = arr[i].second;
        if(end>=s) {
            if(end<e) {
                end = e;
            } 
        } else {
            ans += end-start;
            start = s, end = e;
        }
    }
    ans += end-start;
    cout << ans << "\n";

    return 0;
}
