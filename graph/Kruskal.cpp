#include <iostream>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
const int mx = 1e6 + 5;
const long int inf = 2e9;
typedef long long ll;
#define rep(i, n) for (i = 0; i < n; i++)
#define repp(i, a, b) for (i = a; i <= b; i++)
#define pii pair<int, int>
#define vpii vector<pii>
#define vi vector<int>
#define vll vector<ll>
#define r(x) scanf("%d", &x)
#define rs(s) scanf("%s", s)
#define gc getchar_unlocked
#define pc putchar_unlocked
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
// void in(int &x)
// {
// 	register int c = gc();
// 	x = 0;
// 	int neg = 0;
// 	for (; ((c < 48 || c > 57) && c != '-'); c = gc())
// 		;
// 	if (c == '-')
// 	{
// 		neg = 1;
// 		c = gc();
// 	}
// 	for (; c > 47 && c < 58; c = gc())
// 	{
// 		x = (x << 1) + (x << 3) + c - 48;
// 	}
// 	if (neg)
// 		x = -x;
// }
// void out(int n)
// {
// 	int N = n, rev, count = 0;
// 	rev = N;
// 	if (N == 0)
// 	{
// 		pc('0');
// 		return;
// 	}
// 	while ((rev % 10) == 0)
// 	{
// 		count++;
// 		rev /= 10;
// 	}
// 	rev = 0;
// 	while (N != 0)
// 	{
// 		rev = (rev << 3) + (rev << 1) + N % 10;
// 		N /= 10;
// 	}
// 	while (rev != 0)
// 	{
// 		pc(rev % 10 + '0');
// 		rev /= 10;
// 	}
// 	while (count--)
// 		pc('0');
// }
ll parent[mx], arr[mx], node, edge;
vector<pair<ll, pair<ll, ll>>> v;
void initial()
{
	int i;
	rep(i, node + edge)
		parent[i] = i;
}
int root(int i)
{
	while (parent[i] != i)
	{
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}
void join(int x, int y)
{
	int root_x = root(x); //Disjoint set union by rank
	int root_y = root(y);
	parent[root_x] = root_y;
}

/****************main kruskal function************************/
ll kruskal()
{
	ll mincost = 0, i, x, y;
	rep(i, edge)
	{
		x = v[i].second.first;
		y = v[i].second.second;
		if (root(x) != root(y))
		{
			mincost += v[i].first;
			join(x, y);
		}
	}
	return mincost;
}
int main()
{
	fast;
	while (1)
	{
		int i, j, from, to, cost, totalcost = 0;
		cin >> node >> edge; //Enter the nodes and edges
		if (node == 0 && edge == 0)
			break; //Enter 0 0 to break out
		initial(); //Initialise the parent array
		rep(i, edge)
		{
			cin >> from >> to >> cost;
			v.pb(mp(cost, mp(from, to)));
			totalcost += cost;
		}
		sort(v.begin(), v.end());
		// rep(i,v.size())
		// 	cout<<v[i].first<<"  ";
		cout << kruskal() << endl;
		v.clear();
	}
	return 0;
}

   

/********************My Own Implementation for CP ****************************/

// O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. 
// After sorting, we iterate through all edges and apply the 
// find-union algorithm. The find and union operations can 
// take at most O(LogV) time. So overall complexity is 
// O(ELogE + ELogV) time. The value of E can be at most O(V2), 
// so O(LogV) is O(LogE) the same. Therefore, 
// the overall time complexity is O(ElogE) or O(ElogV)

// Kruskal O(ElogE) works by sorting all the edges in the graph first; 
// thus for a sparse graph this is indeed better than Prims..
// Prims O(E.logV) on the other hand doesn't need this 
// sorting of edges. It works by adding a unique 
// node to resultant set in each step. For a denser 
// graph, this is certainly better than Kruskal..

#include<bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>>> mp;
int parent[10001];
int r_ank[10001];
int f_ind(int a)          //path compression...
{
    if(parent[a]<0)
        return(a);
    return(parent[a]=f_ind(parent[a]));
}

void uni_on(int a,int b)           // union by rank..
{
    if(r_ank[a]>r_ank[b])
    {
        r_ank[a]+=r_ank[b];
        parent[b]=a;
    }
    else
    {
        r_ank[b]+=r_ank[a];
        parent[a]=b;
    }
}

struct edge
{
    int a;
    int b;
    int w;
};

edge edgelist[100001];
bool comp(edge a,edge b)
{
    if(a.w<b.w)
        return true;
    return false;
}
int main()
{
    int n,m,u,v,w,x;
    cin>>n>>m;

     memset(parent,-1,sizeof(parent));
     memset(r_ank,1,sizeof(r_ank));
      mp.clear();


    for(int i=0;i<m;i++)
    {
      //  cin>>edgelist[i].a>>edgelist[i].b>>edgelist[i].w;
      cin>>u>>v>>w;
      mp[w].push_back({u,v});
    }


  //  sort(edgelist,edgelist+m,comp);        // sorting user defined quantities...
    int sum=0;
    for(int i=1;i<1000;i++)
    {
        if(mp[i].empty()) continue;


      while(!mp[i].empty())                                   // this is kruskals algo being implemented...
      {
          int f=mp[i][mp[i].size()-1].first;   // vertex 1
        int s=mp[i][mp[i].size()-1].second;    // vertex 2
         mp[i].pop_back();
        if(f_ind(f)!=f_ind(s))
        {
            uni_on(f_ind(f),f_ind(s));
            sum+=i;
        }


      
       }


}cout<<sum<<"\n";
}




/******************** A more clear implementation ******************************/


const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}

/*************************************************************************/