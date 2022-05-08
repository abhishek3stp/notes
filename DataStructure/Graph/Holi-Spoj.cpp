#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<pair<int, int>> *G;

public:
    Graph(int v)
    {
        this->v = v;
        G = new list<pair<int, int>>[v];
    }

    void addEdge(int a, int b, int w)
    {
        G[a].push_back(make_pair(b, w));
        G[b].push_back(make_pair(a, w));
    }

    int dfs_helper(int start, vector<bool> &visit, vector<int> &count, int &ans)
    {
        visit[start] = true;
        count[start] = 1;
        for (auto x : G[start])
        {
            if (!visit[x.first])
            {
                count[start] += dfs_helper(x.first, visit, count, ans);
                int nx = count[x.first];
                int ny = v - nx;
                ans += 2 * min(nx, ny) * x.second;
            }
        }
        return count[start];
    }

    int dfs()
    {
        vector<bool> visit(v, false);
        vector<int> count(v, 0);
        int ans = 0;
        dfs_helper(0, visit, count, ans);
        return ans;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);

    cout << g.dfs() << endl;
}
