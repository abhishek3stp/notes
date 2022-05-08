#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[], int n)
{
    int nsr[n];
    stack<int> s;
    s.push(n - 1);
    nsr[n - 1] = n;

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() and arr[i] <= arr[s.top()])
            s.pop();

        if (s.empty())
            nsr[i] = n;
        else
            nsr[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    int nsl[n];
    s.push(0);
    nsl[0] = -1;

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() and arr[i] <= arr[s.top()])
            s.pop();

        if (s.empty())
            nsl[i] = -1;
        else
            nsl[i] = s.top();
        s.push(i);
    }

    int area = 0;
    for (int i = 0; i < n; i++)
        area = max(area, arr[i] * (nsr[i] - nsl[i] - 1));

    return area;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(int);

    cout << getMaxArea(arr, n) << endl;
    return 0;
}
