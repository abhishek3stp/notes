#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> G;

public:
    void addEdge(int a, int b)
    {
        G[a].push_back(b);
    }

    int bfs(int start, int end)
    {
        map<int, int> dist;
        map <int,int> parent;
        for (auto x : G)
            dist[x.first] = INT_MAX;

        queue<int> q;
        q.push(start);
        dist[start] = 0;
        parent[start] = start;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (auto x : G[temp])
            {
                if (dist[x] == INT_MAX)
                {
                    q.push(x);
                    dist[x] = dist[temp] + 1;
                    parent[x] = temp;
                }
            }
        }

        int temp = end;
        while(temp != start)
        {
            cout << temp << " <- ";
            temp = parent[temp];
        }
        cout << temp << endl;

        return dist[end];
    }
};

int main()
{
    int board[100] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -31;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph g;
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
                g.addEdge(i, j);
        }
    }
    g.addEdge(36, 36);
    cout << g.bfs(0, 36);
}
