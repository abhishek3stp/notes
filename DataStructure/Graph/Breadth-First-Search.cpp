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

    void bfs(int start)
    {
        vector<bool> visit(v, false);
        queue<int> q;
        q.push(start);
        visit[start] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            cout << temp << " ";

            for (auto x : G[temp])
            {
                if (!visit[x])
                {
                    q.push(x);
                    visit[x] = true;
                }
            }
        }
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
    g.bfs(0);
}
