#include <iostream>
#include <vector>

using namespace std;
int ans=0; int k; 
vector<int> tree[51];
int dfs(int node){
    if(node == k) return -1;

    if(tree[node].size() == 0){
        ans++;
        return 0;
    }
    for(int i=0; i < tree[node].size(); i++){
        int tmp = dfs(tree[node][i]);
        if (tmp == -1 && tree[node].size() == 1)
			ans++;
        
    }   
    return 0;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);



    int n; cin >> n;
    int root;

    for(int i=0; i < n; i++){
        int t1;
        cin >> t1;
        if(t1 == -1) root = i;
        else tree[t1].push_back(i);
    }
    cin >> k;
    dfs(root);
    cout << ans;
    
}