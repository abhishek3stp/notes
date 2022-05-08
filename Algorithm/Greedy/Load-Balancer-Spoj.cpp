#include <bits/stdc++.h>
using namespace std;

int load_balancer(int arr[], int n)
{
    int load = 0, max_load = 0, diff = 0;

    for (int i = 0; i < n; i++)
        load += arr[i];

    if (load % n != 0)
        return -1;

    load = load / n;

    for (int i = 0; i < n; i++)
    {
        diff += (arr[i] - load);
        max_load = max(max_load, abs(diff));
    }

    return max_load;
}

int main()
{
    int arr[] = {6, 0, 0, 10};
    int n = sizeof(arr) / sizeof(int);

    cout << load_balancer(arr, n) << endl;
}
