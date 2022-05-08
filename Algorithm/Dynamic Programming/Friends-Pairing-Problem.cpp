#include <bits/stdc++.h>
using namespace std;

int friendPair(int n)
{
    if (n <= 2)
        return n;

    return friendPair(n - 1) + (n - 1) * friendPair(n - 2);
}

int friendPairBU(int n)
{
    int dp[n + 1];

    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 5;
    cout << friendPair(n) << endl;
    cout << friendPairBU(n) << endl;
}
