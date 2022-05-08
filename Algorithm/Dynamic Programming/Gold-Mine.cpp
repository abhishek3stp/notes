#include <bits/stdc++.h>
using namespace std;

int maxGoldBU(vector<vector<int>> &arr)
{
    vector<vector<int>> dp(arr);
    int n = arr.size();

    for (int col = n - 1; col >= 0; col--)
        for (int row = 0; row < n; row++)
        {
            if (col == n - 1)
                dp[row][col] = arr[row][col];

            else if (row == 0)
                dp[row][col] = arr[row][col] + max(dp[row][col + 1], dp[row + 1][col + 1]);

            else if (row == n - 1)
                dp[row][col] = arr[row][col] + max(dp[row][col + 1], dp[row - 1][col + 1]);

            else
                dp[row][col] = arr[row][col] + max(dp[row][col + 1], max(dp[row + 1][col + 1], dp[row - 1][col + 1]));
        }

    int ans = INT_MIN;
    for (int row = 0; row < n; row++)
        ans = max(ans, dp[row][0]);

    return ans;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}};

    cout << maxGoldBU(arr) << endl;
}
