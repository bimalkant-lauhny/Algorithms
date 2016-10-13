#include<bits/stdc++.h>
using namespace std;

#define INIT 0
#define PROC 1
#define VSTD 2
#define NODES 6

vector <int> adjlist[NODES];
bool status[NODES];

void DFS_visit(int vertex)
{
	cout << vertex << " ";
	int current = vertex;
	status[current] = PROC;
	for(int i=0;i<adjlist[current].size();i++)
	{
		if(status[adjlist[current][i]] == INIT)
			DFS_visit(adjlist[current][i]);
	}
	status[current] = VSTD;
}

int main()
{
	int u,v,w;
    
    while(true) 
    {
        cin >> u >> v;
        if(u==v)
            break;
        adjlist[u].push_back(v);      
    }
    
    cout << endl << "Adjacency List Formed: " << endl;
    
    for(int j=0;j<NODES;j++)
    {
    	cout << j << " : ";
    	for(int i=0;i<adjlist[j].size();i++)
    		cout << adjlist[j][i] << " ";
    	cout << endl;
    }
    
    cout << endl;
    
    for(int i=0;i<NODES;i++)
		status[i] = INIT;
		
	cout << "Initialised!!!" << endl;	
	
	for(int i=0;i<NODES;i++)
	{
		if(status[i] == INIT)
			DFS_visit(i);
	}
	
	cout << endl;
		
	return 0;
}
