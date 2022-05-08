#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
    int n, ans = 0;
    int arr[] = {2, 3, 5};
    cin >> n;
    int mask = (1 << 3);
    for (int i = 1; i < mask; i++)
    {
        int denominator = 1;
        int setbits = __builtin_popcount(i);
        for (int j = 0; j < 3; j++)
        {
            if (i & (1 << j))
                denominator = denominator * arr[j];
        }
        if (setbits & 1)
            ans += (n / denominator);
        else
            ans -= (n / denominator);
    }
    cout << ans << endl;
}