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

bool isSafe(ll arr[],int cows,int n,ll mid)
{

    int init = 1;
    int diff=0;
    for(int i=1;i<n;i++)
    {
        diff+=(arr[i]-arr[i-1]);

        if(diff>=mid)
        {
            init++;
            diff=0;

             if(init>=cows)
               return true;

        }



    }

    return false;



}
int main()
{
    fast_in_out;
   int t=1;
    cin>>t;
    while(t--)
{
         int n,c;
         ll xi;
         cin>>n>>c;

         ll arr[n];

         for(int i=0;i<n;i++)
         {
             cin>>arr[i];
         }

         sort(arr,arr+n);
         ll low = 0;
         ll high =0;
         for(int i=1;i<n;i++)
         {
             high+=(arr[i]-arr[i-1]);
         }

         //BS
         ll ans=INT_MIN;
         while(low<=high)
         {
             ll mid = low + (high - low)/2;

             if(isSafe(arr,c,n,mid))
             {
                 //right
                 ans = max(ans,mid);
                 low = mid+1;
             }
             else
             {
                 //left
                 high = mid-1;
             }


         }
         cout<<ans<<"\n";


}



}
