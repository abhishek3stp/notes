#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> arr)
{
    int maxSum = INT_MIN, currentSum;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            currentSum += arr[j];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

int kadaneAlgo(vector<int> arr)
{
    int maxSum = INT_MIN, currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {-4, 1, 3, -2, 6, 2, -1, -4, -7};
    cout << maxSum(arr) << endl;
    cout << kadaneAlgo(arr) << endl;
    return 0;
}
