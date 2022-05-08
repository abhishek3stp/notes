#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int coins[], int m, int dp[])
{
    if (n == 0)
        return 0;

    if (dp[n] != 0)
        return dp[n];

    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
        if (n - coins[i] >= 0)
        {
            int subans = minCoins(n - coins[i], coins, m, dp);
            ans = min(ans, subans + 1);
        }
    dp[n] = ans;
    return dp[n];
}

int minCoinsBU(int n, int coins[], int m)
{
    int dp[100] = {0};

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < m; j++)
            if (i - coins[j] >= 0)
            {
                int subans = dp[i - coins[j]];
                dp[i] = min(dp[i], subans + 1);
            }
    }
    return dp[n];
}

int main()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins) / sizeof(int);
    int n = 11;
    int dp[100] = {0};
    cout << minCoins(n, coins, m, dp) << endl;
    cout << minCoinsBU(n, coins, m) << endl;
}
