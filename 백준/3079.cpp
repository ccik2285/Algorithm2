#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> t;
int n,m;
bool check(long long mid){
    long long people = 0;
    for(int i=0; i < n; i++){
        people += mid / t[i];
    }
    if(people >= m) return true;
    else return false;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    cin >> n >> m;
	t.resize(n, 0); 
	long long low, high, result; 
	low = high = result = 0;  
	for (int i = 0; i < n; i++) { 
		cin >> t[i]; 
		high = max(high, t[i]); 
	}

    high *=m;
    result = high;
    while(low <=high){
        long long mid = (low + high) / 2;
        if(check(mid)){
            high = mid - 1;
            result = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << result;
}