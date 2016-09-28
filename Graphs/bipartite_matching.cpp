#include <bits/stdc++.h>
using namespace std;

#define NIL 0
#define RED 1
#define BLACK 2

class Graph
{
	int V;

public:
	vector <int> *adjList;
	Graph(int n)
	{
		V = n;
		adjList = new vector <int> [n+1];
	}

	void addUndirEdge(int u, int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	~Graph()
	{
		delete [] adjList;
	}
};

bool isBipartite(Graph &g, int n)
{
	queue <int> q;

	int *color = new int [n+1];
	fill(color, color + n + 1, NIL);

	q.push(1);
	color[1] = RED;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		int v;
		for(int i=0; i<g.adjList[u].size(); i++)
		{
			v = g.adjList[u][i];

			if(color[v] == NIL)
			{
				color[v] = (color[u] == RED) ? BLACK: RED;
				q.push(v);
			}
			else if(color[u] == color[v])
			{
				delete[]  color;
				return false;
			} 	
		}
	}

	delete[] color;
	return true;
}

int main()
{
	int scenarios;
	scanf("%d", &scenarios);

	for(int i=1; i <= scenarios; i++)
	{
		int n, e;
		scanf("%d %d", &n, &e);

		Graph g(n);

		int u, v;
		while(e--)
		{
			scanf("%d %d", &u, &v);
			g.addUndirEdge(u, v);
		}

		printf("Scenario #%d:\n", i);
		
		if(isBipartite(g, n) == true)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");

	}
	return 0;
}