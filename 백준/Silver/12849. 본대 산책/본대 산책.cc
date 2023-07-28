#include <iostream>

using namespace std;

long long dp[8], nxt[8];

int main()
{
	int d;
	cin >> d;

	dp[0] = 1;
	while (d--)
	{
		nxt[0] = dp[1] + dp[2];
		nxt[1] = dp[0] + dp[2] + dp[3];
		nxt[2] = dp[0] + dp[1] + dp[3] + dp[4];
		nxt[3] = dp[1] + dp[2] + dp[4] + dp[5];
		nxt[4] = dp[2] + dp[3] + dp[5] + dp[6];
		nxt[5] = dp[3] + dp[4] + dp[7];
		nxt[6] = dp[4] + dp[7];
		nxt[7] = dp[5] + dp[6];

		for (int i = 0; i < 8; i++)
			dp[i] = nxt[i] % 1000000007;
	}

	cout << dp[0];
}