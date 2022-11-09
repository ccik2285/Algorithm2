#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> vt;
    vector<int> cli;
    int m =0;
    int m_max;
    map<int,int> mp;

    for(int i=0; i < n; i++){
        int a;
        cin >> a;
        vt.push_back(a);
        mp[a]++;
        if(mp[a] > m) {m = mp[a];}
    }
    for(auto a : mp){
        if(a.second == m){
            cli.push_back(a.first);
        }
    }
    sort(cli.begin(),cli.end());
    if(cli.size() > 1){
        m_max = cli[1];
    }
    else m_max = cli[0];
    int avg = floor(double(accumulate(vt.begin(),vt.end(),0)/double(n)) + 0.5);
    sort(vt.begin(),vt.end());
    int cent = vt[n/2];
    int range = vt[vt.size()-1]-vt[0];

    cout << avg << endl;
    cout << cent << endl;
    cout << m_max << endl;
    cout << range << endl;
    

}