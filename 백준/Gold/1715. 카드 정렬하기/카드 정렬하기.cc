#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int,vector<int>,greater<int>> q;
    int n; cin >> n;

    for(int i=0; i < n; i++){
        int a; cin >> a;
        q.push(a);
    }
    int curr = 0;
    while(q.size() > 1){
        int first = q.top(); q.pop();
        int second = q.top(); q.pop();  

        curr += first + second;
        q.push(first + second);

    }
    cout << curr;

}