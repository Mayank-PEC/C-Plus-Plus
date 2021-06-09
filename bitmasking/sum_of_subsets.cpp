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



// subset sum using bitwise operations
void SubsetSums(ll arr[],int st,int en,vector<ll> &vec)
{
     // n -->number of subsets possible
      int n = en -st +1;
    for(int mask=0;mask<(1<<n);mask++)  //masks
    {
        int sum =0;
       for(int j=0;j<n;j++)  //index of the array
       {
           int f = 1<<j;

           if( (mask&f)!=0 )
           {
               sum +=arr[j];
           }
       }
        vec.pb(sum);
    }


}

int main()
{
    fast_in_out;
   int t=1;
  //  cin>>t;
    while(t--)
{
          int n;
          ll a,b;

          cin>>n>>a>>b;

          ll arr[n];
          for(int i=0;i<n;i++)
            cin>>arr[i];

         // vector<ll> v1,v2;  

}



}
