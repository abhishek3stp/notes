#include <bits/stdc++.h>
using namespace std;

int uniqueNumber(vector<int> arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
        ans = ans ^ arr[i];

    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 3, 1, 2, 2, 4};
    cout << uniqueNumber(arr) << endl;

    return 0;
}
