// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool dfs(int src,vector<int> adj[],bool vis[],bool rec[])
    {
        vis[src]=1;
        rec[src]=1;
        for(int c:adj[src])
        {
            if(!vis[c])
              {
                  if(dfs(c,adj,vis,rec)==true)
                    return true;
              }
              
            else
            {
                if(rec[c])           //  (c!=par) --->undirected graph
                  return true;
            }
        }
        rec[src]=0;
        return false;
    }
    bool bfs_undirected_graph(int src,vector<int> adjlist[],bool vis[],int parent[])
{
       queue<int> q;
       
       q.push(src);
       
       while(!q.empty())
       {
           int u=q.front();
           q.pop();
           
           vis[u]=1;
           
           for(int c:adjlist[u])
           {
               if(!vis[c])
               {
                   q.push(c);
                   
                   parent[c]=u;
               }
               
               else
               {
                   if(c!=parent[u])
                     return true;
               }
           }
       }
       
       return false;
}

    
    bool solve_bfs_directed_graph(bool visited[],int V,vector<int> adjlist[])
    {
        
        // it is simple just think that if the 
        // topological sort array is not equal to 
        //the number of vertices then we have a cycle...
        
        
       int  indegree[V]={0};
        for(int i=0;i<V;i++)
        {
            for(int c:adjlist[i])
            {
                indegree[c]++;
            }
           
        }
        
      queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
               q.push(i);
        }
        
        
      //  vector<int> topo;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            visited[u]=1;
            
        //    topo.push_back(u);
            
            for(int c:adjlist[u])
            {
                if(!visited[c])
                {
                    indegree[c]--;
                      
                      if(indegree[c]==0)
                        q.push(c);
                    
                }
            }
        }
    
        for(int i=0;i<V;i++)
         {
             if(indegree[i]!=0)
                return 1;
         }
         
         return 0;
        
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	
	   	
	   	// using dfs
	  /******************************************	 
	   bool vis[V]={0};
	   	 bool rec[V]={0};
	   	 for(int i=0;i<V;i++)
	   	 {
	   	     if(!vis[i])
	   	     {
	   	         if(dfs(i,adj,vis,rec))
	   	              return true;
	   	     }
	   	        
	   	     
	   	 }
	   	 
	   	 return 0; 
	   	 *********************************************/
	   	
	   	
	   	// using bfs
	   	bool vis[V];
	   	
	   	memset(vis,0,sizeof(vis));
	   	
	   	return solve_bfs(vis,V,adj);
	   	
	   	
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends