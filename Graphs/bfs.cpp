#include <bits/stdc++.h>
using namespace std;

#define INIT 0
#define WAIT 1
#define VSTD 2

class Graph
{
	int vertices, edges;
	vector <int> *adjlist;
	int *status;
	
	public:
	
	Graph(int v, int e)
	{
		vertices = v;
		edges = e;
		adjlist = new vector<int> [vertices+1];	
	}
	
	void add_edge(int u, int v)
	{
		adjlist[u].push_back(v);
	}
	
	void BFS()
	{
		int *status = new int [vertices+1];
		fill(status, status+vertices+1, INIT);
		
		queue <int> bfsq;
		bfsq.push(0);
		
		status[0] = WAIT;
	
		while(!bfsq.empty())
		{
			int current = bfsq.front();
			status[current] = VSTD;
			bfsq.pop();
			for(int i=0;i<adjlist[current].size();i++)
			{
				if(status[adjlist[current][i]] == INIT)
				{
					bfsq.push(adjlist[current][i]);
					status[adjlist[current][i]] = WAIT;
				}		
			}
		}
		
		delete [] status;
	}
	
	~Graph()
	{
		delete [] adjlist;
	}
	
};

int main()
{   
    cout << "Enter number of vertices in the graph:\n";
    int v;
    cin >> v;
    
    cout << "Enter the number of edges:\n";
    int e;
    cin >> e;
    
    Graph g(v,e);
    
    cout << "Enter edges (u v):\n";
    int i,j;
    
    while(e--) 
    {
        cin >> i >> j;
        g.add_edge(i, j);      
    }
    
    g.BFS();
    cout << "Breadth First Search complete!\n";
	
	return 0;
}
