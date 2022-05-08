#include <bits/stdc++.h>
using namespace std;

int join_ropes(int rope[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(rope, rope + n);

    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}

int main()
{
    int rope[] = {4, 3, 2, 6};
    int n = sizeof(rope) / sizeof(int);

    cout << join_ropes(rope, n) << endl;
}
