#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define umpii unordered_map<int,int>
#define mem(a,b) memset(a, b, sizeof a)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define fast_in_out ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<pair<int,int>> adjlist[100001];
bitset<100001> vis;
int n;
int  sizes[100001];


int dfs(int src,int par)
{
    int s=1;
    for(pii child:adjlist[src])
    {
        if(child.first==par)
            continue;

            int temp=dfs(child.first,src);
            s+=temp;

    }
     sizes[src]=s;

    return s;

}

int main()
{
    fast_in_out;
   int t=1;
    cin>>t;
    for(int k=1;k<=t;k++)
{

        int x,y,z;
        cin>>n;
        for(int i=0;i<100001;i++)
             adjlist[i].clear();
        vis.reset();

        for(int i=0;i<n-1;i++)
        {
            cin>>x>>y>>z;
            adjlist[x].pb({y,z});
            adjlist[y].pb({x,z});
        }



           dfs(1,0);

    

        

}



}
