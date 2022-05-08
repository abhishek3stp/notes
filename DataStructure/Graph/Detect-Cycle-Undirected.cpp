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

    bool detectCycle()
    {
        vector<bool> visit(v, false);
        vector<int> parent(v);

        for (int i = 0; i < v; i++)
            parent[i] = i;

        queue<int> q;
        q.push(0);
        visit[0] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (auto x : G[temp])
            {
                if (visit[x] == false)
                {
                    visit[x] = true;
                    parent[x] = temp;
                    q.push(x);
                }
                else if (parent[temp] != x)
                    return true;
            }
        }
        return false;
    }

    bool dfs_helper(int start, vector<bool> &visit, int parent)
    {
        visit[start] = true;

        for (auto x : G[start])
        {
            if (visit[x] == false)
            {
                if (dfs_helper(x, visit, start))
                    return true;
            }
            else if (x != parent)
                return true;
        }
        return false;
    }

    bool detectCycleDFS()
    {
        vector<bool> visit(v, false);
        return dfs_helper(0, visit, 0);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    cout << g.detectCycle() << endl;
    cout << g.detectCycleDFS() << endl;
}
