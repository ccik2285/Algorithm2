#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}


int main() {
    vector<vector<int>> v ={{10,2}, {1,3}, {2,4}, {9,8}, {7,7}, {9,1}};
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i < v.size(); i++){
        cout << v[i][0] << " " << v[i][1] << endl;
    }
}