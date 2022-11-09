#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    map<char,int> mp;
    cin >> s;
    for(int i=0; i < s.size(); i++){
        mp[s[i]]++;
    }
    for(int i= 'a'; i <= 'z'; i++){
        cout << mp[i] << " ";
    }
}