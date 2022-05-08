#include <bits/stdc++.h>
using namespace std;

int coin_change(int coins[], int n, int amt)
{
    int ans = 0;
    while (amt > 0)
    {
        int idx = upper_bound(coins, coins + n, amt) - 1 - coins;
        amt -= coins[idx];
        ans++;
    }
    return ans;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int n = sizeof(coins) / sizeof(int);

    int amt = 39;
    cout << coin_change(coins, n, amt) << endl;
    return 0;
}
