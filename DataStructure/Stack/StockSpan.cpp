#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> price)
{
    stack<int> s;
    vector<int> span;
    span.push_back(1);

    s.push(0);

    for (int i = 1; i < price.size(); i++)
    {
        while (!s.empty() and price[s.top()] <= price[i])
            s.pop();

        if (!s.empty())
            span.push_back(i - s.top());
        else
            span.push_back(i + 1);

        s.push(i);
    }
    return span;
}

int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = stockSpan(price);

    for (auto x : ans)
        cout << x << ", ";
    cout << endl;
}
