#include <iostream>
#include <limits.h>
#include <string.h>

using namespace std;

//Wrapper class for storing a graph
class Graph
{
public:
	int vertexNum;
	int **edges;

	//Constructs a graph with V vertices and E edges
	Graph(int V)
	{
		this->vertexNum = V;
		this->edges = (int **)malloc(V * sizeof(int *));
		for (int i = 0; i < V; i++)
		{
			this->edges[i] = (int *)malloc(V * sizeof(int));
			for (int j = 0; j < V; j++)
				this->edges[i][j] = INT_MAX;
			this->edges[i][i] = 0;
		}
	}

	//Adds the given edge to the graph
	void addEdge(int src, int dst, int weight)
	{
		this->edges[src][dst] = weight;
	}
};

//Utility function to print distances
void print(int dist[], int V)
{
	cout << "\nThe Distance matrix for Floyd - Warshall" << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{

			if (dist[i * V + j] != INT_MAX)
				cout << dist[i * V + j] << "\t";
			else
				cout << "INF"
					 << "\t";
		}
		cout << endl;
	}
}

//The main function that finds the shortest path from a vertex
//to all other vertices using Floyd-Warshall Algorithm.
void FloydWarshall(Graph graph)
{
	int V = graph.vertexNum;
	int dist[V][V];

	//Initialise distance array
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			dist[i][j] = graph.edges[i][j];

	//Calculate distances
	for (int k = 0; k < V; k++)
		//Choose an intermediate vertex

		for (int i = 0; i < V; i++)
			//Choose a source vertex for given intermediate

			for (int j = 0; j < V; j++)
				//Choose a destination vertex for above source vertex

				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
					//If the distance through intermediate vertex is less than direct edge then update value in distance array
					dist[i][j] = dist[i][k] + dist[k][j];

	//Convert 2d array to 1d array for print
	int dist1d[V * V];
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			dist1d[i * V + j] = dist[i][j];

	print(dist1d, V);
}

//Driver Function
int main()
{
	int V, E;
	int src, dst, weight;
	cout << "Enter number of vertices: ";
	cin >> V;
	cout << "Enter number of edges: ";
	cin >> E;
	Graph G(V);
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
	FloydWarshall(G);

	return 0;
}


/******************************** MY implementation for CP *****************************/

// The Floyd Warshall Algorithm is for solving the All Pairs 
// Shortest Path problem. The problem is to find shortest distances
//  between every pair of vertices in a given edge weighted directed Graph. 

// This algorithm is also used to find shortest distances 
// between every pair of vertices in a given edge weighted UNDIRECTED graph.


// 1. does it work for -ve weights?   ans  ----> yes
// 2. does it work for undirected graph?  ans ---> yes 
// but it should not contain -ve cycle 

//Detect if negative cycle exists.
// for (i = 0; i < V; i++)
// for (j = 0; j < V; j++)
// if( i == j && matrix[i][j] != 0 )
// cout << "Negative cycle detected!\n" << endl;
// self loops are always taken as zero in the input graph



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	              matrix[i][j]=INT_MAX;
	        }
	    }
	    
	    
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	               if(i==j || i==k || j==k)
	                  continue;
	                  
	                  
	               if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX) //VVIP STEP...
	                      matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	     for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==INT_MAX)
	              matrix[i][j]=-1;
	        }
	    }
	    
	    
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));

		// taken a matrix as it is best suited for this algorithm
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  

/************************************************************************************/


