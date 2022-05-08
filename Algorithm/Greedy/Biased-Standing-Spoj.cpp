#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, rank;
        string name;
        cin >> n;
        long long freq[n + 1] = {0};

        for (long long i = 0; i < n; i++)
        {
            cin >> name >> rank;
            freq[rank]++;
        }

        long long actual_rank = 1, ans = 0;

        for (long long i = 1; i <= n; i++)
        {
            while (freq[i])
            {
                ans += abs(actual_rank - i);
                freq[i]--;
                actual_rank++;
            }
        }
        cout << ans << endl;
    }
}
