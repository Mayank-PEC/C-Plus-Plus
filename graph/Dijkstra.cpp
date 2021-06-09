#include <bits/stdc++.h>
using namespace std;

/**********************************Dijstra using adj list **********************************/

// In metric representation: condition is different for which dist[v] populating,
// Dijkstra's -> dist[v] = dist[u] + graph[u][v]
// Prim's ---> dist[v] = graph[u][v]
// One is calculating MST other one is SPT.
// both are DIFFERENT Algos, NOT same, hence the output is, only input is same for both.
//O(ELogV) algorithm for adjacency list 



#define INF 10000010
vector<pair<int,int>> adjlist[5 * 100001];
int dis[5 * 100001];
bitset<5*100001> vis;
int dij(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    // source distance to zero.
    // pairs ---> {dist,vertex}
    pq.push({0,s});
    dis[s] = 0;
    vis.reset();
    while (!pq.empty())
    {
        int u = (pq.top()).second;
        pq.pop();
    //A vertex once popped in dijkstra can't have another minimum path than what it already has.


        if(vis[u])
            continue;
        vis[u]=1;
        for ( pair<int,int> child:adjlist[u])
        {
            if ( vis[child.first]==0 && dis[u] + child.second < dis[child.first] )
            {
                dis[child.first] = dis[u] + child.second;
                pq.push({dis[child.first],child.first});
            }
        }
    }
}


// dijkstra can be applied for both directed and undirected
int main()
{
    int m, n, l, x, y, w,s;
    // n--> number of nodes , m --> number of edges
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        // input edges.
        cin>>x>>y>>w;
        adjlist[x].push_back({y,w});
        adjlist[y].push_back({x,w}); // comment this line for directed graph
    }
    // start node.
    cin>>s;
    // intialise all distances to infinity.
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dij( s);

    for (int i = 1; i <= n; i++)
        if (dis[i] == INF)
            cout << "-1 ";
        else
            cout << dis[i] << " ";
    return 0;
}











/*************************Dijkstra using adj matrix****************************/





// int minDistance(int dist[], bool sptSet[])
// {
//     // Initialize min value
//     int min = INT_MAX, min_index;
  
//     for (int v = 0; v < V; v++)
//         if (sptSet[v] == false && dist[v] <= min)
//             min = dist[v], min_index = v;
  
//     return min_index;
// }
  
// // Function that implements Dijkstra's single source shortest path algorithm
// // for a graph represented using adjacency matrix representation
// void dijkstra(int graph[V][V], int src)
// {
//     int dist[V]; // The output array.  dist[i] will hold the shortest
//     // distance from src to i
  
//     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
//     // path tree or shortest distance from src to i is finalized
  
//     // Initialize all distances as INFINITE and stpSet[] as false
//     for (int i = 0; i < V; i++)
//         dist[i] = INT_MAX, sptSet[i] = false;
  
//     // Distance of source vertex from itself is always 0
//     dist[src] = 0;
  
//     // Find shortest path for all vertices
//     for (int count = 0; count < V - 1; count++) {
//         // Pick the minimum distance vertex from the set of vertices not
//         // yet processed. u is always equal to src in the first iteration.
//         int u = minDistance(dist, sptSet);
  
//         // Mark the picked vertex as processed
//         sptSet[u] = true;
  
//         // Update dist value of the adjacent vertices of the picked vertex.
//         for (int v = 0; v < V; v++)
  
//             // Update dist[v] only if is not in sptSet, there is an edge from
//             // u to v, and total weight of path from src to  v through u is
//             // smaller than current value of dist[v]
//             if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
//                 && dist[u] + graph[u][v] < dist[v])
//                 dist[v] = dist[u] + graph[u][v];
//     }
  
// }
  
// // driver program to test above function
// int main()
// {
//     /* Let us create the example graph discussed above */
//     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//                         { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//                         { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//                         { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//                         { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//                         { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//                         { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//                         { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//                         { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
//     dijkstra(graph, 0);
  
//     return 0;
// }