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

    bool dfs_helper(int start, vector<int> &visit, int colour)
    {
        visit[start] = colour;
        for (auto x : G[start])
        {
            if (visit[x] == 0)
            {
                int subans = dfs_helper(x, visit, 3 - colour);
                if (subans == false)
                    return false;
            }
            else if (colour == visit[x])
                return false;
        }
        return true;
    }

    bool dfs()
    {
        vector<int> visit(v, 0);
        int colour = 1;
        return dfs_helper(0, visit, colour);
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    cout << g.dfs() << endl;
}
