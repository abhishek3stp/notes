#include <bits/stdc++.h>
using namespace std;

int threeUniqueNumber(vector<int> arr)
{
    int cnt[64] = {0};

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i], j = 0;
        while (temp > 0)
        {
            int lastbit = (temp & 1);
            cnt[j] += lastbit;
            j++;
            temp = temp >> 1;
        }
    }

    int p = 1, ans = 0;
    for (int i = 0; i < 64; i++)
    {
        cnt[i] %= 3;
        ans += cnt[i] * p;
        p = p << 1;
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 3, 1, 1, 1, 2, 3};
    cout << threeUniqueNumber(arr) << endl;

    return 0;
}
