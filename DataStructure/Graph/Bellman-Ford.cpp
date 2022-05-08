#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> edgeList;

public:
    Graph(int v)
    {
        this->V = v;
    }

    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({x, y, w});
    }

    void bellmanFord(int start)
    {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto edge : edgeList)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }

        for (auto edge : edgeList)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
            {
                cout << "Negative Cycle found" << endl;
                exit(0);
            }
        }

        for (int i = 0; i < V; i++)
            cout << i << " " << dist[i] << endl;
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(0, 2, -10);

    g.bellmanFord(0);
}
