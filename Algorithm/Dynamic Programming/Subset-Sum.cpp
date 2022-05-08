#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;

    if (n == 0 && sum > 0)
        return false;

    if (set[n - 1] > sum)
        return subsetSum(set, n - 1, sum);

    else
        return subsetSum(set, n - 1, sum) or subsetSum(set, n - 1, sum - set[n - 1]);
}

bool subsetSumBU(int set[], int n, int sum)
{
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
        {
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - set[i - 1]];
        }

    return dp[n][sum];
}

int main()
{
    int set[] = {1, 5, 11, 5};
    int sum = 11;
    int n = sizeof(set) / sizeof(int);

    cout << subsetSum(set, n, sum) << endl;
    cout << subsetSumBU(set, n, sum) << endl;
}
