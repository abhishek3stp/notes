#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *G;

public:
    Graph(int v)
    {
        this->v = v;
        G = new list<int>[v];
    }

    void addEdge(int a, int b)
    {
        G[a].push_back(b);
        G[b].push_back(a);
    }

    void dfs_helper(int start, vector<bool> &visit)
    {
        cout << start << " ";
        visit[start] = true;
        for (auto x : G[start])
        {
            if (!visit[x])
                dfs_helper(x, visit);
        }
    }

    void dfs(int start)
    {
        vector<bool> visit(v, false);
        dfs_helper(start, visit);
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);
}
