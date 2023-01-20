#include <iostream>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int a=0;
    for(int i=0; i < s.size(); i++){
        if(s[i] == 'a'){
            a++;
        }
    }

    int ans = s.size();
    for(int i=0; i < s.size(); i++){
        int cnt=a; int tmp=0;
        for(int j=i; j < j+s.size(); j++){
            if(cnt==0) break;
            if(s[j%s.size()]=='b') {cnt--; tmp++;}
            else cnt--;
        }
        ans = min(ans,tmp);
    }
    
    cout << ans;


}