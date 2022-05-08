#include <bits/stdc++.h>
using namespace std;

bool campare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> v;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            int dist, cap;
            cin >> dist >> cap;
            v.push_back(make_pair(dist, cap));
        }

        sort(v.begin(), v.end(), campare);

        int total_d, fuel;
        cin >> total_d >> fuel;

        for (int i = 0; i < n; i++)
            v[i].first = total_d - v[i].first;

        int prev = 0, curr = 0, ans = 0; // Logic
        bool flag = true;

        while (curr < n)
        {
            if (fuel >= (v[curr].first - prev))
            {
                fuel -= (v[curr].first - prev);
                pq.push(v[curr].second);
                prev = v[curr].first;
            }
            else
            {
                if (pq.empty())
                {
                    flag = false;
                    break;
                }
                fuel += pq.top();
                pq.pop();
                ans++;
                continue;
            }
            curr++;
        }

        if (!flag)
        {
            cout << -1 << endl;
            continue;
        }

        total_d = total_d - v[n - 1].first;
        if (fuel >= total_d)
        {
            cout << ans << endl;
            continue;
        }

        while (fuel < total_d)
        {
            if (pq.empty())
            {
                flag = false;
                break;
            }
            else
            {
                fuel += pq.top();
                pq.pop();
                ans++;
            }
        }

        if (flag)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}
