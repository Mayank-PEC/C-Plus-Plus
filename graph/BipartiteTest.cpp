// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
     
     bool color[100005];
     bool vis[100005];
     bool dfs(int node,bool col,int par,vector<int> adjlist[])
     {
         color[node]=col;
         vis[node]=1;
         for(int child:adjlist[node])
         {
            if(!vis[child])
             {
                 if(!dfs(child,col^1,node,adjlist))
                    return false;
             }
             
             else
             {
                 if(color[child]==color[node])
                 {
                     return false;
                 }
             }
         }
         return true;
     }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    memset(color,0,sizeof(color));
	    memset(vis,0,sizeof(vis));
	    
	    for(int i=0;i<V;i++)  //case where the graph might not be connected 
	                       // then we need to iterate to find specific connected 
	                        // components that are not bipartite that is 
	                         // have odd length cycle....
	    {
	       if(!vis[i]) 
	      if(!dfs(i,0,-1,adj))
	         return 0;
	    }
	    return 1;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  
// } Driver Code Ends