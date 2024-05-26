#include <iostream>
#include <string>
using namespace std;

long long int dp[4];

int main() {


	int slen; string s; cin >> slen >> s;
	for (auto& l : s) {
		if (l == 'E') {
			dp[3] += dp[3] + dp[2];
			while (dp[3] > 1000000006) dp[3] -= 1000000007;
			dp[2] += dp[1];
			if (dp[2] > 1000000006) dp[2] -= 1000000007;
		}
		else if (l == 'H') {
			dp[1] += dp[0];
			if (dp[1] > 1000000006) dp[1] -= 1000000007;
		}
		else if (l == 'W') {
			dp[0]++;
		}
	}

	cout << dp[3];
}