#include <iostream>
#include <limits.h>

using namespace std;

//Wrapper class for storing an edge
class Edge
{
public:
	int src, dst, weight;
};

//Wrapper class for storing a graph
class Graph
{
public:
	int vertexNum, edgeNum;
	Edge *edges;

	//Constructs a graph with V vertices and E edges
	Graph(int V, int E)
	{
		this->vertexNum = V;
		this->edgeNum = E;
		this->edges = (Edge *)malloc(E * sizeof(Edge));
	}

	//Adds the given edge to the graph
	void addEdge(int src, int dst, int weight)
	{
		static int edgeInd = 0;
		if (edgeInd < this->edgeNum)
		{
			Edge newEdge;
			newEdge.src = src;
			newEdge.dst = dst;
			newEdge.weight = weight;
			this->edges[edgeInd++] = newEdge;
		}
	}
};

//Utility function to print distances
void print(int dist[], int V)
{
	cout << "\nVertex  Distance" << endl;
	for (int i = 0; i < V; i++)
	{
		if (dist[i] != INT_MAX)
			cout << i << "\t" << dist[i] << endl;
		else
			cout << i << "\tINF" << endl;
	}
}

//The main function that finds the shortest path from given source
//to all other vertices using Bellman-Ford.It also detects negative
//weight cycle
void BellmanFord(Graph graph, int src)
{
	int V = graph.vertexNum;
	int E = graph.edgeNum;
	int dist[V];

	//Initialize distances array as INF for all except source
	//Intialize source as zero
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	//Calculate shortest path distance from source to all edges
	//A path can contain maximum (|V|-1) edges
	for (int i = 0; i <= V - 1; i++)
		for (int j = 0; j < E; j++)
		{
			int u = graph.edges[j].src;
			int v = graph.edges[j].dst;
			int w = graph.edges[j].weight;

			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}

	//Iterate inner loop once more to check for negative cycle
	for (int j = 0; j < E; j++)
	{
		int u = graph.edges[j].src;
		int v = graph.edges[j].dst;
		int w = graph.edges[j].weight;

		if (dist[u] != INT_MAX && dist[u] + w < dist[v])
		{
			cout << "Graph contains negative weight cycle. Hence, shortest distance not guaranteed." << endl;
			return;
		}
	}

	print(dist, V);

	return;
}

//Driver Function
int main()
{
	int V, E, gsrc;
	int src, dst, weight;
	cout << "Enter number of vertices: ";
	cin >> V;
	cout << "Enter number of edges: ";
	cin >> E;
	Graph G(V, E);
	for (int i = 0; i < E; i++)
	{
		cout << "\nEdge " << i + 1 << "\nEnter source: ";
		cin >> src;
		cout << "Enter destination: ";
		cin >> dst;
		cout << "Enter weight: ";
		cin >> weight;
		G.addEdge(src, dst, weight);
	}
	cout << "\nEnter source: ";
	cin >> gsrc;
	BellmanFord(G, gsrc);

	return 0;
}




/***************************** My implementation for CP ******************************/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    int dist[n];
	    for(int i=0;i<n;i++)
	      dist[i]=INT_MAX;
	      
	      dist[0]=0;
	    for(int i=0;i<=n-1;i++)
	    {
	        for(int r=0;r<edges.size();r++)
	        {
	            if(dist[edges[r][0]]!=INT_MAX && dist[edges[r][1]]>dist[edges[r][0]]+edges[r][2])
	              dist[edges[r][1]]=dist[edges[r][0]]+edges[r][2];
	        }
	    }
	   
	   for(int r=0;r<edges.size();r++)
	        {
	            if(dist[edges[r][0]]!=INT_MAX &&  dist[edges[r][1]]>dist[edges[r][0]]+edges[r][2])
	                   return 1;
	            
	        }
	   
	  
	   
	   return 0; 
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  

/*************************************************************************/








// Ques :- Can we use Dijksra’s algorithm for shortest paths for graphs
//  with negative weights – one idea can be, calculate the minimum 
//  weight value, add a positive value (equal to absolute value of 
//  minimum weight value) to all weights and run the Dijksra’s 
//  algorithm for the modified graph. Will this algorithm work?

// Ans :- this doesn't work because shortest path with a lot 
// of edges may have bigger weight than a longer path 
// with less edges.

//can someone please explain why are we repeating the process |v| -1 times?
//Cause a vertice can have at most v - 1 edges, since there are v Vertices including it

