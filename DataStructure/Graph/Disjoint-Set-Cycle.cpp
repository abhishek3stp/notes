#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<pair<int, int>> G;

public:
    Graph(int v)
    {
        this->v = v;
    }

    void addEdge(int a, int b)
    {
        G.push_back(make_pair(a, b));
    }

    int find(int i, vector<int> &parent) // Path Compression
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i], parent);
    }

    void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) // Union by Rank
    {
        int s1 = find(a, parent);
        int s2 = find(b, parent);

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

    bool detectCycle()
    {
        vector<int> parent(v);
        vector<int> rank(v);

        for (int i = 0; i < v; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for (auto edge : G)
        {
            int s1 = find(edge.first, parent);
            int s2 = find(edge.second, parent);

            if (s1 != s2)
                unionSet(s1, s2, parent, rank);
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    cout << g.detectCycle() << endl;
}
