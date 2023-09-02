#include <iostream>

using namespace std;

int parent[500000];

int find_parent(int n){
    if(parent[n] == n) return n;
    else return parent[n] = find_parent(parent[n]);
}
int make(int a,int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a == b){
        return 1;
    }
    else {
        parent[a] = b;
        return 0;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m; cin >> n >> m;
    int ans = 0;
    for(int i=0; i < n; i++){
        parent[i] = i;
    }

    int a,b;
    for(int i=1; i <= m; i++){
        cin >> a >> b;
        if(make(a,b)){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    


}