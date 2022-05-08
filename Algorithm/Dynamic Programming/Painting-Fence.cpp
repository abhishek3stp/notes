#include <bits/stdc++.h>
using namespace std;

int paintFenceBU(int n, int k)
{
    if (n == 1)
        return k;

    int same = k;
    int diff = k * (k - 1);
    int total = same + diff;

    for (int i = 3; i <= n; i++)
    {
        same = diff * 1;
        diff = total * (k - 1);
        total = same + diff;
    }

    return total;
}

int main()
{
    int n = 4, k = 3;
    cout << paintFenceBU(n, k) << endl;
}
