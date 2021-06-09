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

vector<int> adjlist[100005];
int FT[2*100005];
int start[100005];
int term[100005];
int timer=0;


void Euler_tour(int src,int par)
{
    start[src]=++timer;
    FT[timer]=src;

    for(int child:adjlist[src])
    {
        if(par==child)
            continue;
        Euler_tour(child,src);

    }
    term[src]=++timer;
    FT[timer]=src;


}


int main()
{
    fast_in_out;
   int t=1;
    //cin>>t;
    while(t--)
{

        int n,type,x,y;
        cin>>n;

        for(int i=0;i<n-1;i++)
        {
             
            cin>>x>>y;
            adjlist[x].pb(y);
            adjlist[y].pb(x);
        }

        Euler_tour(1,0);

        // for(int i=1;i<=8;i++)
        //     cout<<FT[i]<<" ";
        // cout<<"\n";
        // for(int i=1;i<=4;i++)
        //     cout<<start[i]<<" ";
        // cout<<"\n";
        // for(int i=1;i<=4;i++)
        //     cout<<term[i]<<" ";
        // cout<<"\n";

       
}



}
