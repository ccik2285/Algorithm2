#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int res =0;
int main() {
    int n;
    vector<string> arr;
    string s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >>  s;
        arr.push_back(s);
    }
    sort(arr.begin(),arr.end());
    for(int i=0; i<arr.size(); i++){
        int bol = 0;
        for(int j= i+1; j<arr.size(); j++){
            if(arr[j].find(arr[i]) == 0) bol = 1;
        }
        if(bol) res++;
    }
    cout << n - res;
}