#include <bits/stdc++.h>
using namespace std;

void negativeComeFirst(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {2, -1, -3, 5, 6, -2, 3, -10};
    negativeComeFirst(arr);

    for (auto e : arr)
        cout << e << " ";

    return 0;
}
