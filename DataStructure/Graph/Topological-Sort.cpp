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

	void dfs_helper(int start, vector<bool> &visit, list<int> &order)
	{
		visit[start] = true;
		for (auto x : G[start])
		{
			if (!visit[x])
				dfs_helper(x, visit, order);
		}
		order.push_front(start);
	}

	void topologicalSort()
	{
		vector<bool> visit(v, false);
		list<int> order;

		for (int i = 0; i < v; i++)
			if (!visit[i])
				dfs_helper(i, visit, order);

		for (auto x : order)
			cout << x << " ";
	}

	void topologicalSortBFS()
	{
		vector<int> inDegree(v, 0);

		for (int i = 0; i < v; i++)
			for (auto x : G[i])
				inDegree[x]++;

		queue<int> q;

		for (int i = 0; i < v; i++)
			if (inDegree[i] == 0)
				q.push(i);

		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			cout << temp << " ";

			for (auto x : G[temp])
			{
				inDegree[x]--;
				if (inDegree[x] == 0)
					q.push(x);
			}
		}
	}
};

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	g.topologicalSort();
	g.topologicalSortBFS();
}
