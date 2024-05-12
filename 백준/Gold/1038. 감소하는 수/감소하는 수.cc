#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int n; cin >> n;
    vector<long long> v;
    queue<long long> q;
    for(int i=0; i <= 9; i++){
        v.push_back(i);
        q.push(i);
    }
    
    while(!q.empty()){
        long long num = q.front();
        int last = q.front() % 10;
        q.pop();

        for(int i=0; i < last; i++){
            long long tmp = num * 10 + i;
            q.push(tmp);
            v.push_back(tmp);
        } 
    }

    if(n >= v.size()){
        cout << -1;
    }
    else {
        cout << v[n];
    }

}