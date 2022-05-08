#include <bits/stdc++.h>
using namespace std;

bool campare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n, start, end;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), campare);

    int ans = 1;
    int finish = v[0].second;

    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= finish)
        {
            finish = v[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}
