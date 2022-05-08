#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int v)
    {
        for (int i = 0; i < v; i++)
        {
            parent.push_back(-1);
            rank.push_back(1);
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unionSet(int a, int b)
    {
        int s1 = find(a);
        int s2 = find(b);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    int v;
    vector<vector<int>> edgeList;

public:
    Graph(int v)
    {
        this->v = v;
    }

    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({w, x, y});
    }

    int kruskal()
    {
        sort(edgeList.begin(), edgeList.end());

        DSU s(v);
        int ans = 0;

        for (auto edge : edgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y))
            {
                s.unionSet(x, y);
                ans += w;
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

    cout << g.kruskal() << endl;
}
