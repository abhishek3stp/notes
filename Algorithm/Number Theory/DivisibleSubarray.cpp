// You are given m elements, a1,a2,a3….an. Find the number of good sub-arrays.
// Good Sub-array is a Sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by n.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll freq[100005] = {0};
        int temp, n, sum = 0;
        cin >> n;
        freq[0] = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            sum += temp;
            sum = ((sum % n) + n) % n;
            freq[sum]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += (freq[i] * (freq[i] - 1)) / 2;

        cout << ans << endl;
    }
}
