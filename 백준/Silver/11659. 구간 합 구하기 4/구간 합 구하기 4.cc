#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,m; 
    int sum[100001] = {0,};
    cin >> n >> m;

    for(int i=1; i <= n; i++){
        int a; cin >> a;
        sum[i] = a;
    }
    for(int i=2; i <= n; i++){
        sum[i] += sum[i-1]; 
    }
    for(int i=0; i < m; i++){
        int a,b; cin >> a >> b;
        int c = b - a;
        printf("%d\n",sum[b] - sum[b-1-c]);
    }
}
