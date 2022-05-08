#include <bits/stdc++.h>
using namespace std;

int n = 4;
int allvisit = (1 << n) - 1;

int dp[1 << 4][4]; // 2^n number of possible mask

int tsp(int mask, int pos, vector<vector<int>> &dist)
{
    if (mask == allvisit)
        return dist[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int smallans = dist[pos][city] + tsp(mask | (1 << city), city, dist);
            ans = min(smallans, ans);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}};

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    cout << tsp(1, 0, dist) << endl; // 1 is mask for 0th node
}
