#include <iostream>
using namespace std;
 
int N, M;
int arr[300];
 
bool isPossible(int mid) {
    int sum = 0, groupCnt = 1;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum > mid){
            sum = arr[i];
            groupCnt++;
        }
    }
    return groupCnt <= M;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    int left = 0, right = 0, mid;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        left = left < arr[i] ? arr[i] : left;
        right += arr[i];
    }
        
    while (left <= right) {
        mid = (left + right) / 2;
        if(isPossible(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    int cur = left;
    cout << cur << '\n';
 
    int i, sum = 0, marbleCnt = 0;
    for (i=0; i < N; i++) {
        sum += arr[i];
        if (sum > cur) {
            sum = arr[i];
            M--;
            cout << marbleCnt << " ";
            marbleCnt = 0;
        }
        marbleCnt++;
        if (N - i == M) break;
    }
    while (M--){
        cout << marbleCnt << " ";   
        marbleCnt = 1;
    }
}