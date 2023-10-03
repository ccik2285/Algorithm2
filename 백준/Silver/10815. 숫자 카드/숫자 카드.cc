#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> vt;
    vector<int> card;
    cin >> n;
    for(int i=0; i < n; i++) {int a; cin >> a; vt.push_back(a);}
    int m;
    cin >> m;
    for(int i=0; i < m; i++) {int a; cin >> a; card.push_back(a);}
    sort(vt.begin(),vt.end());

    for(int i=0; i < m; i++){
       int target = card[i];
       int low = 0;
       int high = n-1;
       bool flag = false;
       while(low <= high){
            int mid = (low + high) / 2;

            if(target == vt[mid]){
                flag = true;
                break;
            }

            if(target < vt[mid]){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
       }
       if(flag){
            cout << 1 << " ";
       }
       else cout << 0 << " ";
    }


}