#include <iostream>
#include <map>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        int c; cin >> c;
        map<long long,int> mp;
        bool flag = false;
        long long ans = 0;
        for(int j=0; j < c; j++){
            long long a; cin >> a;          
            mp[a]++;
            
            if(mp[a] > c/2) {
                flag = true;
                ans = a;
            }
        }
        if(flag) {
            cout << ans << endl;
        } 
        else {
            cout << "SYJKGW" << endl;
        }

    }
}