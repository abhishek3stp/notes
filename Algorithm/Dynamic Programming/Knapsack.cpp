#include <bits/stdc++.h>
using namespace std;

int knapsackBU(int val[], int wt[], int n, int cap)
{
    int dp[n + 1][cap + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= cap; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;

            else if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);

            else
                dp[i][j] = dp[i - 1][j];
        }

    return dp[n][cap];
}

int main()
{
    int wt[] = {2, 5, 1, 3, 4};
    int val[] = {15, 14, 10, 45, 30};
    int cap = 7;
    int n = sizeof(val) / sizeof(int);

    cout << knapsackBU(val, wt, n, cap) << endl;
}
