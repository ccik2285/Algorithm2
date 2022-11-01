#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    string al = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;

    for(int i=0; i < al.size(); i++){
        if(s.find(al[i]) != string::npos) cout << s.find(al[i]);
        else cout << -1;

        if(i != al.size()-1) cout << " ";
    }
}