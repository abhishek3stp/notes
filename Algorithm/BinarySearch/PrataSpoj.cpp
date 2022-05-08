#include <bits/stdc++.h>
using namespace std;

bool canCook(int p, int m, int rank[], int max_time)
{
    int currPrata = 0;
    for (int i = 0; i < m; i++)
    {
        int time = 0, count = 1;
        while (time + (rank[i] * count) <= max_time) // is possible to make next prata
        {
            time += rank[i] * count;
            currPrata++;
            count++;
        }
        if (currPrata >= p)
            return true;
    }
    return false;
}

int main()
{
    int prata, n, sum = 0;
    cin >> prata >> n;
    int rank[n];
    for (int i = 0; i < n; i++)
        cin >> rank[i];

    for (int i = 1; i <= prata; i++) // time taken by fastest cook alone
        sum += rank[0] * i;

    int s = 0, e = sum;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (canCook(prata, n, rank, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    cout << ans;
}
