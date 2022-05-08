#include <bits/stdc++.h>
using namespace std;

int profit(int wine[], int i, int j, int year, int dp[][100])
{
    if (i > j)
        return 0;

    if (dp[i][j] != 0)
        return dp[i][j];

    int left = wine[i] * year + profit(wine, i + 1, j, year + 1, dp);
    int right = wine[j] * year + profit(wine, i, j - 1, year + 1, dp);

    return dp[i][j] = max(left, right);
}

int profitBU(int wine[], int n)
{
    int dp[n][n];

    for (int gap = 0; gap < n; gap++)
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            int year = n - gap;

            if (gap == 0)
                dp[i][j] = wine[i] * year;
            else
                dp[i][j] = max(dp[i + 1][j] + wine[i] * year, dp[i][j - 1] + wine[j] * year);
        }

    return dp[0][n - 1];
}

int main()
{
    int wine[] = {2, 3, 5, 1, 4};
    int dp[100][100] = {0};
    int n = sizeof(wine) / sizeof(int);

    cout << profit(wine, 0, n - 1, 1, dp) << endl;
    cout << profitBU(wine, n) << endl;
}
