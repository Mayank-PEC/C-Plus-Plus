//Function to find sum of weights of edges of the Minimum Spanning Tree.
//O(ELogV) algorithm for adjacency list representation
// If we take a closer look, we can observe that the statements in
// inner loop are executed O(V+E) times (similar to BFS). The inner
// loop has decreaseKey() operation which takes O(LogV) time. So
//  overall time complexity is O(E+V)*O(LogV) which is
//   O((E+V)*LogV) = O(ELogV) (For a connected graph, V = O(E))

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1001];  // vertex,price
bool vis[1001];
int Prims(int start,int v)
	{
	    int key[v+1];
	    for(int i=0;i<v;i++)
	    {
	         key[i]=INT_MAX;
	    }

	      key[start]=0;
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	      // pq --> (weight , vertex)
	    pq.push({0,start});

	    int weight=0;
	    while(!pq.empty())
	    {
	        int vertex = pq.top().second;
	        int value = pq.top().first;
	        pq.pop();
	          if(!vis[vertex])
	               weight+=key[vertex];
	        else
                continue;
	        vis[vertex]=1;

	        for(pair<int,int> child:adj[vertex])
	        {
	            if(!vis[child.first])
	            {
	                if(child.second < key[child.first])
	                {
	                    key[child.first] = child.second;
	                    pq.push({key[child.first],child.first});
	                }
	            }
	        }
	    }

	    return weight;



	}
int spanningTree(int V, vector<pair<int,int>> adj[])
    {


      /*  for(int i=0;i<V;i++)
        {
           // cout<<i<<"--->";
            for(vector<int> child:adj[i])
            {
                for(int j=0;j<child.size();j+=2)
                  {
                      //cout<<ele<<"---";
                      adjlist[i].push_back({child[j],child[j+1]});
                    //  adjlist[j].push_back({i,child[j+1]});
                  }
            }//cout<<"\n";


        }*/

    //  for(int i=0;i<V;i++)
    //   {
    //       cout<<i<<"--->";
    //       for(pair<int,int> child:adjlist[i])
    //       {
    //           cout<<"("<<child.first<<" "<<child.second<<")"<<"---";
    //       }cout<<"\n";
    //   }

      memset(vis,0,sizeof(vis));
      return Prims(0,V);



    }



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        int i=0;
        /*  for(int i=0;i<1001;i++)
                 adj[i].clear();*/

        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }


    	cout << spanningTree(V, adj) << "\n";
    }

    return 0;
}



// A group of edges that connects two set of vertices
//  in a graph is called cut in graph theory. So, at
//  every step of Prim’s algorithm, we find a cut
//  (of two sets, one contains the vertices already
//  included in MST and other contains rest of the
//  vertices), pick the minimum weight edge from the
//   cut and include this vertex to MST Set (the set
//    that contains already included vertices).



/****************************A more clear code *********************************/

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}

/*******************************************************************/
