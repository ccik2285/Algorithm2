#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    do {
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        if(s == tmp) {cout << tmp; break;}
    }while(next_permutation(s.begin(),s.end()));
    cout << "I'm Sorry Hansoo";
}