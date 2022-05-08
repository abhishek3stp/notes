#include <bits/stdc++.h>
using namespace std;

int knapsackBU(int val[], int wt[], int n, int cap)
{
    int dp[cap + 1] = {0};

    for (int i = 1; i <= cap; i++)
        for (int j = 0; j < n; j++)
        {
            if (wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
        }

    return dp[cap];
}

int main()
{
    int wt[] = {2, 5, 1, 3, 4};
    int val[] = {15, 14, 10, 45, 30};
    int cap = 7;
    int n = sizeof(val) / sizeof(int);

    cout << knapsackBU(val, wt, n, cap) << endl;
}
