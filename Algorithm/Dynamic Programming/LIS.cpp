#include <bits/stdc++.h>
using namespace std;

int lisBU(int arr[], int n)
{
    int len[n];

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        len[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && len[i] < len[j] + 1)
                len[i] = len[j] + 1;
        }
        ans = max(ans, len[i]);
    }
    return ans;
}

int main()
{
    int arr[] = {3, 2, 1, 3, 5, 4, 4, 5, 6, 3};
    int n = sizeof(arr) / sizeof(int);
    cout << lisBU(arr, n);
}
