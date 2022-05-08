#include <bits/stdc++.h>
using namespace std;

int triangleCount(vector<pair<int, int>> &a)
{
    unordered_map<int, int> x;
    unordered_map<int, int> y;

    for (int i = 0; i < a.size(); i++)
    {
        x[a[i].first]++;
        y[a[i].second]++;
    }

    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (x[a[i].first] >= 1 and y[a[i].second] >= 1)
            count += (x[a[i].first] - 1) * (y[a[i].second] - 1);
    }
    return count;
}

int main()
{
    vector<pair<int, int>> a;
    a.push_back(make_pair(1, 2));
    a.push_back(make_pair(2, 1));
    a.push_back(make_pair(2, 2));
    a.push_back(make_pair(2, 3));
    a.push_back(make_pair(3, 2));

    cout << triangleCount(a) << endl;
    return 0;
}
