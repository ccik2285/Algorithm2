#include <iostream>

using namespace std;

int main() {

    long long int dp[4][100001]= {0,};

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[1][3] = 1;
    dp[2][3] = 1;
    dp[3][3] = 1;

    for(int i=4; i < 100001; i++){   
        dp[1][i] = (dp[2][i-1] + dp[3][i-1]) % 1000000009;
        dp[2][i] = (dp[1][i-2] + dp[3][i-2]) % 1000000009;
        dp[3][i] = (dp[1][i-3] + dp[2][i-3]) % 1000000009;

    }

    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        int a; cin >> a;
        cout << (dp[1][a] + dp[2][a] + dp[3][a]) % 1000000009 << "\n";
    }
}