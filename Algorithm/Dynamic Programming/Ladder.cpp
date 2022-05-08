#include <bits/stdc++.h>
using namespace std;

int ladder(int n, int k, int dp[])
{
    if (n == 0)
        return 1;

    if (dp[n] != 0)
        return dp[n];

    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            ways += ladder(n - i, k, dp);
    }
    return dp[n] = ways;
}

int ladderBU(int n, int k)
{
    int dp[100] = {0};

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            if (i - j >= 0)
                dp[i] += dp[i - j];
    }

    return dp[n];
}

int main()
{
    int n = 6, k = 3;
    int dp[100] = {0};
    cout << ladder(n, k, dp) << endl;
    cout << ladderBU(n, k) << endl;
}
