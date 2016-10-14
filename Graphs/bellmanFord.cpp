#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF 999

vector < pair <int,int> > adjlist[8];
int pred[8], dist[8];

int main()
{
    int u,v,w=1;
    
    while(true) 
    {
        cin >> u >> v >> w;
        if(w==0)
            break;
        adjlist[u].push_back(make_pair(v,w));      
    }
    
    for(int i=0;i<8;i++)
    {
        pred[i] = NIL;
        dist[i] = INF;
    }
    
    dist[0] = 0;
    
    for(int k=0;k<8;k++)
    for(int i=0;i<8;i++)
    {		
        for(int j=0;j<adjlist[i].size();j++)
        {
            if(dist[i] + adjlist[i][j].second < dist[adjlist[i][j].first] )
            {
                dist[adjlist[i][j].first] = dist[i] + adjlist[i][j].second;
                pred[adjlist[i][j].first] = i;
            }
        }
    }
    
    bool negCycle = false;
    
    for(int i=0;i<8;i++)
    {		
        for(int j=0;j<adjlist[i].size();j++)
        {
            if(dist[i] + adjlist[i][j].second < dist[adjlist[i][j].first] )
            {
             	negCycle = true;
             	break;   
    		}
        }
        if(negCycle)
        	break;
    }
    
    if(negCycle)
    	cout << "Negative Cycle Present!!!" << endl;
   	else
    	for(int i=0;i<8;i++)
    	{
    	    cout << i << " " << pred[i] << " " << dist[i] << endl;
    	}
    return 0;
}
