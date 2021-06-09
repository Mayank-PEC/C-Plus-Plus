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
#define N 11
#define mod 1000000000

// in this code the value of the 
// transformation matrix is also 
// changing ...
// that is why it is different from
// the matrix exponentiation code

/*  https://ide.codingblocks.com/s/2215    ----->  Coding blocks code   */

ll I[N][N],trans[N][N],fib[N];
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

         int k,n;
         cin>>k;

         int B[k],C[k];


         for(int i=0;i<k;i++)
            cin>>B[i];


         for(int i=0;i<k;i++)
            cin>>C[i];

          cin>>n;

          if(n==0)
            cout<<0<<"\n";
         else  if(n<=k)
             cout<<B[n-1]<<"\n";
          else
          {


          for(int i=0;i<k;i++)
           {
             fib[i]=B[i];
           }


           memset(trans,0,sizeof(trans));
          for(int i=0;i<k;i++)
          {
              for(int j=0;j<k;j++)
              {
                  if(j==i+1)
                     trans[i][j]=1;

              }
          }



          for(int i=k-1;i>=0;i--)
          {
              trans[k-1][i]=C[k-i-1];
          }


          memset(I,0,sizeof(I));

          power(trans,n-1,k);



 // n ---> this is the nth term

          ll res=0;

          for(int i=0;i<k;i++)
          {
              res = (res + fib[i]*1LL*trans[0][i])%mod;
          }

         cout<<res<<"\n";

          }

}



}


