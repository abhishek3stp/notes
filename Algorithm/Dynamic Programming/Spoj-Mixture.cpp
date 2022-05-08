#include <bits/stdc++.h>
using namespace std;

long long sum(int arr[], int start, int end)
{
    int ans = 0;
    for (int i = start; i <= end; i++)
        ans += arr[i];
    return ans % 100;
}

long long mixture(int arr[], int n)
{
    long long dp[n][n];

    for (int gap = 0; gap < n; gap++)
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 0;

            else
            {
                int ans = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int subans = dp[i][k] + dp[k + 1][j] + sum(arr, i, k) * sum(arr, k + 1, j);
                    ans = min(ans, subans);
                }
                dp[i][j] = ans;
            }
        }

    return dp[0][n - 1];
}

int main()
{
    int arr[] = {40, 60, 20};
    int n = sizeof(arr) / sizeof(int);
    cout << mixture(arr, n) << endl;
}
