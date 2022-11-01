#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    map<string,int> mp;
    cin >> n >> m;
    string s1;
    for(int i=0; i < n; i++){
        cin >> s1;
        mp[s1]++;
    }
    for(int i=0; i < m; i++){
        cin >> s1;
        mp[s1]++;
    }
    int cnt = 0;
    vector<string> vt; 
    for(auto s : mp){
        if(mp[s.first] ==2){
            cnt++;
            vt.push_back(s.first);
        }
    }
    cout << cnt << "\n";
    for(int i=0; i<vt.size(); i++) cout << vt[i] << "\n";
}