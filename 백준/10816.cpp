#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    map<int,int> mp;
    cin >> n;
    for(int i=0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    cin >> n;
    for(int i=0; i < n; i++){
        int b;
        cin >> b;
        cout << mp[b];
        if(i != n-1) cout << " ";
    }
}