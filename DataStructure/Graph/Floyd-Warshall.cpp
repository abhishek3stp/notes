#include <bits/stdc++.h>
using namespace std;
#define max 1000

vector<vector<int>> floydWarshall(vector<vector<int>> &G)
{
    vector<vector<int>> dist(G);
    int v = G.size();

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
    }

    return dist;
}

int main()
{
    vector<vector<int>> G = {
        {0, max, -2, max},
        {4, 0, 3, max},
        {max, max, 0, 2},
        {max, -1, max, 0}};

    auto dist = floydWarshall(G);

    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist.size(); j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}
