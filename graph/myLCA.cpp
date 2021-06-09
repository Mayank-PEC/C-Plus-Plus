#include<bits/stdc++.h>
using namespace std;
vector<int> adjlist[1001];
int level[1000];
int par[1000];
bitset<1000> visited;
int maxN=9;
int n;
int SparseTable[1001][10];

void bfs(int src)
{
    visited[src]=1;
    level[src]=0;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int c:adjlist[u])
        {
            if(!visited[c])
            {
                visited[c]=1;
                level[c]=level[u]+1;
                par[c]=u;
                q.push(c);
            }
        }
    }
}


int LCA1(int a,int b)                 //O(n)
{
    int d;
    if(level[b]>level[a])
        d=level[b]-level[a];
    else
    {
        d=level[a]-level[b];
        swap(a,b);
    }
    while(d>0)
    {
        b=par[b];
        d--;
    }
    if(a==b)
        return(a);
    while(a!=b)
    {
        a=par[a];
        b=par[b];
    }
    return(a);
}



void dfs(int node,int lvl,int parent)
{
    SparseTable[node][0]=parent;
    level[node]=lvl;
    for(int child:adjlist[node])
        if(child!=parent)
            dfs(child,lvl+1,node);
}


void InitializeSparseTable()
{
    dfs(1,0,-1);
    for(int i=1;i<=maxN;i++)   //column
    {
        for(int j=1;j<=n;j++)   //row
        {
            if(SparseTable[j][i-1]!=-1)
            {
                int par=SparseTable[j][i-1];
                SparseTable[j][i]=SparseTable[par][i-1];
            }
        }
    }

}

int LCA2(int a,int b)
{
    if(level[a]>level[b]) swap(a,b);
     int  d=level[b]-level[a];
    while(d)
    {
        int x=log2(d);
        int l=1<<x;
        b=SparseTable[b][x];
        d-=(l);
    }
    if(a==b)
        return(a);
    for(int i=maxN;i>=0;i--)
    {
        if(SparseTable[a][i]!=-1 &&  SparseTable[a][i]!=SparseTable[b][i])
        {
            a=SparseTable[a][i];
            b=SparseTable[b][i];
        }
    }
    return(SparseTable[a][0]);
}
int main()
{
    int t,a,b,m,u,v;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<1001;i++)
            adjlist[i].clear();
        visited.reset();
       // memset(par,-1,sizeof(par));
        memset(level,0,sizeof(level));
        memset(SparseTable,-1,sizeof(SparseTable));
        cin>>n>>m;
        while(m--)
        {
            cin>>u>>v;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

       /* bfs(1);
        cin>>a>>b;
        cout<<LCA1(a,b);*/


        InitializeSparseTable();
        cin>>a>>b;
        cout<<LCA2(a,b)<<"\n";
        for(int r=1;r<=8;r++)
        {
            for(int c=0;c<=3;c++)
            {
                cout<<SparseTable[r][c]<<" ";
            }cout<<"\n";
        }
       cout<<"\n";
        for(int i=1;i<=8;i++)
            cout<<level[i]<<" ";
        cout<<"\n";
        cout<<"Distance between two nodes :"<<"\n";
        cout<<level[a]+level[b]-2*level[LCA2(a,b)];





    }
}
