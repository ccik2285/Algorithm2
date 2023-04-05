#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int arr[100001];
    int n; cin >> n;
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);

    long long int ans = arr[0];
    int cnt = 1;
    int mx = 1;
    for(int i=1; i < n; i++){
        
        if(arr[i] == arr[i-1]){
           cnt++; 
        }
        else {
            cnt = 1;
        }
        if(cnt > mx){
            mx = cnt;
            ans = arr[i];                 
        }

    }
    cout << ans << '\n';
}