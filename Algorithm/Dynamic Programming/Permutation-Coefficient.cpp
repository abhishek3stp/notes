#include <bits/stdc++.h>
using namespace std;

int permutation(int n, int r)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return permutation(n - 1, r) + r * permutation(n - 1, r - 1);
}

int permutationBU(int n, int r)
{
    int fact[n + 1];
    fact[0] = 1;

    for (int i = 1; i <= n; i++)
        fact[i] = i * fact[i - 1];

    return fact[n] / fact[n - r];
}

int main()
{
    int n = 10, r = 2;
    cout << permutation(n, r) << endl;
    cout << permutationBU(n, r) << endl;
}
