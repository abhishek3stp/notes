#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *G;

public:
    Graph(int v)
    {
        this->V = v;
        G = new list<pair<int, int>>[v];
    }

    void addEdge(int a, int b, int wt)
    {
        G[a].push_back(make_pair(b, wt));
        G[b].push_back(make_pair(a, wt));
    }

    void shortestPath(int start)
    {
        set<pair<int, int>> s;
        vector<int> dist(V, INT_MAX);

        s.insert(make_pair(0, start));
        dist[start] = 0;

        while (!s.empty())
        {
            auto it = s.begin();
            int u = it->second;
            s.erase(it);

            for (auto x : G[u])
            {
                int v = x.first;
                int weight = x.second;

                if (dist[v] > dist[u] + weight)
                {
                    if (dist[v] != INT_MAX)
                        s.erase(s.find(make_pair(dist[v], v)));

                    dist[v] = dist[u] + weight;
                    s.insert(make_pair(dist[v], v));
                }
            }
        }

        for (int i = 0; i < V; i++)
            cout << i << " " << dist[i] << endl;
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);
}
