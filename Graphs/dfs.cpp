#include<bits/stdc++.h>
using namespace std;

class Graph{
	int n; // no. of vertices
	list<int> *adj;
	bool visited[100];

public:
	void initGraph(int n){
		this->n = n;
		adj = new list<int>[n+1];
	}

	void addEdge(int v, int w){
		adj[v].push_back(w);
	}

	void DFS(int n, bool* visited){
		cout<<" ->"<<n;
		visited[n] = true;
		list<int>::iterator it;
		for(it = adj[n].begin(); it!= adj[n].end(); ++it){
			if(!visited[*it]){
				DFS(*it, visited);
			}
		}
	}

};


int main(){
	int n;
	cout<<"Enter number of nodes "<<endl;
	cin>>n;
	bool visited[n+1];
	for(int i=0;i<n+1;++i){
		visited[i] = false;
	}

	Graph obj;
	obj.initGraph(n);

	int e;
	cout<<"Enter no. of edges "<<endl;
	cin>>e;
	cout<<"Enter pairs "<<endl;
	int a, b;

	for (int i = 0; i < e; ++i){
		cin>>a>>b;
		obj.addEdge(a,b);
	}

	cout<<"Enter starting vertex \n";
	cin>>a;
	obj.DFS(a, visited);
	return 0;
}
