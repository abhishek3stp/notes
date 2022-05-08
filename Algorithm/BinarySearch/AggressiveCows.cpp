#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int dist, int cow)
{
    int prev_cow = arr[0];
    int count = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - prev_cow >= dist)
        {
            prev_cow = arr[i];
            count++;
        }
    }

    return count >= cow;
}

int aggressiveCow(vector<int> arr, int cow)
{
    int low = 1;
    int high = arr[arr.size() - 1] - arr[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isPossible(arr, mid, cow))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 4, 8, 9};
    int cow = 3;
    cout << aggressiveCow(arr, cow) << endl;

    return 0;
}
