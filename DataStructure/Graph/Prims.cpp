#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<pair<int, int>> *G;

public:
    Graph(int v)
    {
        this->v = v;
        G = new list<pair<int, int>>[v];
    }

    void addEdge(int a, int b, int wt)
    {
        G[a].push_back(make_pair(b, wt));
        G[b].push_back(make_pair(a, wt));
    }

    int prims()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<bool> mst(v, false);
        int ans = 0;

        q.push(make_pair(0, 0));

        while (!q.empty())
        {
            auto it = q.top();
            q.pop();
            int u = it.second, weight = it.first;

            if (mst[u] == true)
                continue;

            ans += weight;
            mst[u] = true;

            for (auto x : G[u])
            {
                if (mst[x.first] == false)
                    q.push(make_pair(x.second, x.first));
            }
        }
        return ans;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    g.addEdge(0, 2, 5);
    g.addEdge(3, 1, 2);
    g.addEdge(3, 2, 40);

    cout << g.prims() << endl;
}
