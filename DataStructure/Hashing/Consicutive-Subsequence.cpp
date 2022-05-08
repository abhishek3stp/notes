#include <bits/stdc++.h>
using namespace std;

int longestConsicutive(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    int max_len = 1;

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int next = arr[i] + 1;
            int len = 1;
            while (s.find(next) != s.end())
            {
                next++;
                len++;
            }
            max_len = max(max_len, len);
        }
    }
    return max_len;
}

int main()
{
    int arr[] = {10, 4, 20, 1, 3, 2, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << longestConsicutive(arr, n) << endl;
}
