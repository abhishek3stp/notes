#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &row, int target)
{
    int low = 0;
    int high = row.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (row[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int findMedian(vector<vector<int>> &A)
{
    int low = INT_MIN;
    int high = INT_MAX;
    int n = A.size();
    int m = A[0].size();

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += count(A[i], mid);

        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    vector<vector<int>> A = {{1, 3, 5},
                             {2, 6, 9},
                             {3, 6, 9}};

    cout << findMedian(A) << endl;
    return 0;
}
