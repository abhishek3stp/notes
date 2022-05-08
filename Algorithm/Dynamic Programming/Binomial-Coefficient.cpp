#include <bits/stdc++.h>
using namespace std;

int binomial(int n, int r)
{
    if (r == 0 or r == n)
        return 1;

    return binomial(n - 1, r - 1) + binomial(n - 1, r);
}

int binomialBU(int n, int r)
{
    int nCr[r + 1] = {0};
    nCr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            nCr[j] = nCr[j] + nCr[j - 1];
    }
    return nCr[r];
}

int main()
{
    int n = 5, r = 2;
    cout << binomial(n, r) << endl;
    cout << binomialBU(n, r) << endl;
}
