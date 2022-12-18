#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
int n,m,k;
vector<long long> arr;
vector<long long> tree;
vector<pair<int,pair<int,long long>>> cmd;
long long mtree(int node,int start,int end) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    long long left = mtree(node*2,start,mid);
    long long right = mtree(node*2+1,mid+1,end);
    tree[node] = left+right;
    return tree[node];
}
void update(int node,int start,int end,int index,int diff) {
    if(start > index || index > end) return ;
    tree[node] = tree[node] + diff;

    if(start !=end){
        int mid = (start+end) /2;
        update(node*2,start,mid,index,diff);
        update(node*2+1,mid+1,end,index,diff);
    }
}
long long sum(int node,int start,int end,int left,int right){
    if(left > end || right < start ) return 0;
    if(left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    long long left_s = sum(node*2,start,mid,left,right);
    long long right_s = sum(node*2+1,mid+1,end,left,right);

    return left_s+right_s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    for(int i=0; i< m+k; i++){
        int a,b,c;
        cin >> a >> b >> c;
        cmd.push_back(make_pair(a,make_pair(b,c)));
    }
    int Tree_Height = (int)ceil(log2(n));
    int Tree_Size = (1 << (Tree_Height + 1));
    tree.resize(Tree_Size);
    mtree(1,0,n-1);
    for(int i=0; i<cmd.size(); i++){
        if(cmd[i].first == 1){
            int index1 = cmd[i].second.first -1 ; // 바꿀것
            long long val = cmd[i].second.second; // 바뀔것
            long long diff = val - arr[index1]; 
            arr[index1] = val;
            update(1,0,n-1,index1,diff);
        }
        else{
            int index1 = cmd[i].second.first-1;
            int index2 = cmd[i].second.second-1;
            long long result = sum(1,0,n-1,index1,index2);
            cout << result << endl;
        }
    }
}