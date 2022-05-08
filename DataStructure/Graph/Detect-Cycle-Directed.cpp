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
    }

    bool dfs_helper(int start, vector<bool> &visit, vector<bool> &stack)
    {
        visit[start] = true;
        stack[start] = true;

        for (auto x : G[start])
        {
            if (visit[x] == false)
            {
                if (dfs_helper(x, visit, stack))
                    return true;
            }
            else if (stack[x] == true)
                return true;
        }

        stack[start] = false;
        return false;
    }

    bool detectCycle()
    {
        vector<bool> visit(v, false);
        vector<bool> stack(v, false);

        bool flag = false;
        for (int i = 0; i < v; i++)
        {
            if (visit[i] == false)
            {
                if (dfs_helper(i, visit, stack))
                    flag = true;
            }
        }
        return flag;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);

    cout << g.detectCycle();
}
