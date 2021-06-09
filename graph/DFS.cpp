#include <bits/stdc++.h>
using namespace std;
int v = 4;
vector<int> adjlist[100001];
bitset<100001> vis;
void dfs(int s)
{
	vis[s] = true;
	cout << s << " ";
	for (int i = 0; i < v; i++)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
}


int main()
{
	int e,u,v;
	while(e--)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

    vis.reset();

	  for(int i=1;i<=v;i++)
	   dfs(i);
}