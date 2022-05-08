#include <bits/stdc++.h>
using namespace std;

int cuttingRod(int price[], int n)
{
    if (n <= 0)
        return 0;

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int subans = price[i] + cuttingRod(price, n - cut);
        ans = max(ans, subans);
    }

    return ans;
}

int cuttingRodBU(int price[], int n)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int len = 1; len <= n; len++)
    {
        int ans = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            int cut = i + 1;
            int subans = price[i] + dp[len - cut];
            ans = max(ans, subans);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(int);

    cout << cuttingRod(price, n) << endl;
    cout << cuttingRodBU(price, n) << endl;
}
