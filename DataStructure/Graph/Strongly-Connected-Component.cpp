#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *G;
    list<int> *T;

public:
    Graph(int v)
    {
        this->v = v;
        G = new list<int>[v];
        T = new list<int>[v];
    }

    void addEdge(int a, int b)
    {
        G[a].push_back(b);
        T[b].push_back(a);
    }

    void dfs1(int start, vector<bool> &visit, stack<int> &s)
    {
        visit[start] = true;
        for (auto x : G[start])
        {
            if (visit[x] == false)
                dfs1(x, visit, s);
        }
        s.push(start);
    };

    void dfs2(int start, vector<bool> &visit)
    {
        cout << start << " ";
        visit[start] = true;
        for (auto x : T[start])
        {
            if (visit[x] == false)
                dfs2(x, visit);
        }
    }

    void ssc()
    {
        vector<bool> visit(v, false);
        stack<int> s;

        for (int i = 0; i < v; i++)
        {
            if (visit[i] == false)
                dfs1(i, visit, s);
        }

        for (int i = 0; i < v; i++)
            visit[i] = false;

        while (!s.empty())
        {
            int start = s.top();
            s.pop();
            if (!visit[start])
            {
                dfs2(start, visit);
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(2, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 3);
    g.addEdge(3, 4);
    g.ssc();
}
