#include <bits/stdc++.h>
using namespace std;

void twoUniqueNumber(vector<int> arr)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
        res = res ^ arr[i];

    int temp = res, pos = 0;

    while ((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }

    int mask = (1 << pos);

    int x = 0, y = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((arr[i] & mask) > 0)
        {
            x = x ^ arr[i];
        }
    }

    y = res ^ x;
    cout << min(x, y) << " " << max(x, y) << endl;
}

int main()
{
    vector<int> arr = {5, 1, 2, 1, 2, 3, 5, 7};
    twoUniqueNumber(arr);

    return 0;
}
