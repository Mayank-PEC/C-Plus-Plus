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
#define N 51
#define mod 1000000007
ll mat[N][N],I[N][N];               //identity matrix --->I
void mul(ll A[][N],ll B[][N],int dim)
{
    ll res[dim+1][dim+1];
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            res[i][j]=0;

            for(int k=0;k<dim;k++)
            {
                res[i][j]= (res[i][j]+ (A[i][k]*1LL*B[k][j])%mod)%mod;
            }
        }
    }

    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            A[i][j]=res[i][j];
        }
    }
}
void power(ll A[][N],int pow,int dim)
{
   // memset(I,0,sizeof(I));
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            if(i==j) I[i][j]=1;
        }
    }

    while(pow>0)
    {
        if(pow&1)
        {
            mul(I,A,dim);
        }
        mul(A,A,dim);
        pow/=2;
    }
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            A[i][j]=I[i][j];
        }
    }

}
int main()
{
    fast_in_out;
   int t=1;
    cin>>t;
    while(t--)
{
      int dim,pow;
      cin>>dim>>pow;
      for(int i=0;i<dim;i++)
      {
          for(int j=0;j<dim;j++)
              cin>>mat[i][j];
      }
      memset(I,0,sizeof(I));
      power(mat,pow,dim);
      for(int i=0;i<dim;i++)
      {
          for(int j=0;j<dim;j++)
          {
              cout<<mat[i][j]<<" ";
          }cout<<"\n";

      }

}



}
