#include <bits/stdc++.h>
using namespace std;

int minCost(int cost[][100], int n, int m)
{
    int dp[n][m] = {0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = cost[i][j];

            else if (i == 0)
                dp[i][j] = dp[0][j - 1] + cost[i][j];

            else if (j == 0)
                dp[i][j] = dp[i - 1][0] + cost[i][j];

            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
        }

    return dp[n - 1][m - 1];
}

int main()
{
    int n = 5, m = 6;
    int cost[100][100] = {
        {0, 4, 1, 2, 3, 2},
        {1, 3, 2, 0, 1, 7},
        {4, 6, 4, 7, 5, 0},
        {2, 5, 1, 3, 9, 8},
        {2, 4, 6, 2, 4, 1}};

    cout << minCost(cost, n, m) << endl;
}
