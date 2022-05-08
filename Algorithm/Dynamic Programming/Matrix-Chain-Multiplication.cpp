#include <bits/stdc++.h>
using namespace std;

int matrix(int arr[], int n)
{
    int dp[n - 1][n - 1];

    for (int gap = 0; gap < n - 1; gap++)
        for (int i = 0, j = gap; j < n - 1; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 0;

            else if (gap == 1)
                dp[i][j] = arr[i] * arr[j] * arr[j + 1];

            else
            {
                int ans = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int subans = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                    ans = min(ans, subans);
                }
                dp[i][j] = ans;
            }
        }

    return dp[0][n - 2];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << matrix(arr, n) << endl;
}
