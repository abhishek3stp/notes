#include <bits/stdc++.h>
using namespace std;

int sumLength(int arr[], int n, int k)
{
    unordered_map<int, int> m;

    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        if (pre == k)
            len = max(len, i + 1);

        if (m.find(pre - k) != m.end())
            len = max(len, i - m[pre - k]);

        if (m.find(pre) == m.end())
            m[pre] = i;
    }
    return len;
}

int main()
{
    int arr[] = {1, -1, 5, -2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << sumLength(arr, n, k);
}
