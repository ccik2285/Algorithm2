#include <iostream>

using namespace std;
long long dp[65][10];
int main() {
    for(int i=0; i<=9; i++){
        dp[1][i] = 1; //  
    }
    for(int i=2; i<=64; i++){
        for(int j=0; j<=9; j++){
            for(int k=j; k<=9; k++){
                dp[i][j] += dp[i-1][k];
            }     
        }
    }
    int f;
    cin >> f;
    while(f--){
    int n;
    cin  >> n;
    
    long long result = 0;
    for(int i=0; i<=9; i++){
        result += dp[n][i];
    } 
    cout << result << "\n";
    }
}