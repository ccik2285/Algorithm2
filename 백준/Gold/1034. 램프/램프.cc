#include <iostream>

using namespace std;

string arr[51];

int main() {
    int n,m;
    cin >> n >> m;

    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    int k; cin >> k;
    int maxcnt = 0;

    for(int i=0; i < n; i++){
        int zerocnt = 0;
        int cnt = 0;
        for(int j=0; j < m; j++){
            if(arr[i][j] == '0'){
                zerocnt++;
            }
        }

        for(int z=0; z < n; z++){
            if(zerocnt <= k && zerocnt % 2 == k % 2){
                if(arr[i] == arr[z]){
                    cnt++;
                }
            }
        }

        maxcnt = max(maxcnt,cnt);

    }

    cout << maxcnt;

}